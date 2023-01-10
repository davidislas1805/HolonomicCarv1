#include "Encoder.h"


Encoder::Encoder()
{

}

Encoder::~Encoder()
{

}

void Encoder::setup(int ppr, const int pins[2]){
  _channelA = pins[0];
  _channelB = pins[1];
  _degrees_pp = 360.0/ppr;
  
  void (*pcb)() = registerCB(this);
  if( pcb ) {
    Serial.print("interrupt");
    pinMode(_channelA, INPUT_PULLUP);
    pinMode(_channelB, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(_channelA), pcb, CHANGE);
    attachInterrupt(digitalPinToInterrupt(_channelB), pcb, CHANGE);
  }
  else {
      // No free callback available in the pool.
  }
}

float Encoder::getRPM(){
  _current_time = micros();
  _time_delta = ((float)(_current_time - _prev_time))/1.0e6;
  _current_pos = (float) _pulse_counter * _degrees_pp;
  noInterrupts();
  _rpm = (((_current_pos - _prev_pos)/ _time_delta) / 60.0);
  if (_rpm == 0){ //Condition to make sure only rpm will be send when the compute is other than zero
    _rpm = _prev_rpm;
  }
  interrupts();
  _prev_rpm = _rpm;
  _prev_pos = _current_pos;
  _prev_time = _current_time;
  return _rpm;
}

float Encoder::getPosition(){
  _position = _pulse_counter * _degrees_pp;
  return _pulse_counter;
}


void Encoder::pollState() {
  // Here is the interrupt handling logic for the class
  old = new_value;
  new_value = digitalRead(_channelA) * 2 + digitalRead(_channelB); // Convert binary input to decimal value
  out = QEM [old * 4 + new_value];
  _pulse_counter = _pulse_counter + out;
}

callback_t callbacks[] = {
  { p0, NULL },
  { p1, NULL },
  { p2, NULL },
  { p3, NULL },
  { p4, NULL }  // Add more records here...
};

void px( callback_t *p ) { if(p->pobj) p->pobj->pollState(); };
void p0() { px(callbacks + 0); };
void p1() { px(callbacks + 1); };
void p2() { px(callbacks + 2); };
void p3() { px(callbacks + 3); };
void p4() { px(callbacks + 4); }; // Add more functions here...

// Callback alocation function. This is called from within the class object constructor
// to find a free callback function for the interrupt registration.
void (*registerCB(Encoder *pobj))() {
  for( int i=0; sizeof(callbacks)/sizeof(callbacks[0]) ; i++ ) {
    if(!callbacks[i].pobj) {
      callbacks[i].pobj = pobj;
      return callbacks[i].pcb;
    }
  }
  return NULL;
}