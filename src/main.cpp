#include <Arduino.h>
#include "Encoder.h"
#include "HOLONOMIC_WHEELS.h"
#include "MOTOR_DIRECTION.h"
#include "PID.h"

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Encoder objects
// Encoder front_right_encoder;
// Encoder rear_right_encoder;
// Encoder rear_left_encoder;
// Encoder front_left_encoder;

// Holonomic drive object
HOLONOMIC_WHEELS direction;
// MOTOR_DIRECTION dir;
// PID pid1;

uint16_t PPR = 912; //912 with tests
ulong current_time;

// Encoder Pins
// int front_right_encoder_pins[2] ={13,12}; 
// int rear_right_encoder_pins[2] ={32,33}; 
// int rear_left_encoder_pins[2] ={23,19}; 
// int front_left_encoder_pins[2] ={15,2}; 

// Motor Pins
byte front_right_motor_pins[2] = {27,14};
// byte right_front_channels[2] = {0, 1};
byte rear_right_motor_pins[2] = {25, 26}; 
byte rear_left_motor_pins[2] = {5,18};
byte front_left_motor_pins[2] = {4, 0};

float count = 0.0, count2 = 0.0, count3 = 0.0, count4 = 0.0, deltaT = 0.0, reference = 15.0, kp = 5.0, ki = 0.9, kd = 0.0; //kp = 4.5 overshoot
volatile int front = 0b1;
int pwm = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("You can pair with the car");
  Dabble.begin("MecanumWheelCAR"); //Bluetooth device name

  // encoder1.setup(PPR,front_right_encoder_pins);
  // encoder2.setup(PPR,rear_right_encoder_pins);
  // encoder3.setup(PPR, rear_left_encoder_pins);
  // encoder4.setup(PPR, front_left_encoder_pins);
  direction.setup(front_right_motor_pins, rear_right_motor_pins, rear_left_motor_pins, front_left_motor_pins);
  // dir.setup(front_right_motor_pins, right_front_channels, HIGH);
  // pid1.setup(kp, ki, kd);
  current_time = micros();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (current_time - micros() > 96){
    deltaT = current_time - micros();
    current_time = micros();
    // count = encoder1.getRPM();
    // count2 = encoder2.getRPM();
    // count3 = encoder3.getRPM();
    // count4 = encoder4.getRPM();
    // Serial.printf("%.2f, %.2f, %.2f, %.2f \n", count, count2, count3, count4);

    Dabble.processInput();
    // float xaxis = (GamePad.getXaxisData() / 7) * 20; 
    // float yaxis = (GamePad.getYaxisData() / 7) * 20;
    // Serial.printf("%d, %d \n", pwm, count);
    // pwm = pid1.control(count, reference, deltaT);
    // dir.move(pwm);
    // direction.forward(pwm);

    if (GamePad.isUpPressed()){
    direction.forward(pwm); //90 of pwm to start moving 1.3rpm to 255 at 43rpm
    }
    else if (GamePad.isDownPressed()){
    direction.backward(pwm); 
    }
    else if (GamePad.isRightPressed()){
    direction.counterClockwise(pwm); 
    }
    else if (GamePad.isLeftPressed()){
    direction.clockwise(pwm); 
    }
    else if (GamePad.isSquarePressed()){
    direction.moveLeft(pwm); 
    }
    else if (GamePad.isCirclePressed()){
    direction.moveRight(pwm); 
    }
    else if (GamePad.isTrianglePressed()){
      if (front == 1){
        direction.forwardRight(pwm);
      }
      else {
        direction.backwardRight(pwm);
      }
    }
    else if (GamePad.isCrossPressed()){
      if (front == 1){
        direction.forwardLeft(pwm);
      }
      else {
        direction.backwardLeft(pwm);
      }
    }
    else if (GamePad.isSelectPressed()){
      front = (front ^ 0b1);
    }
    else{
      direction.stopMoving();
    }
    // Serial.println(count);
    Serial.printf("%i, %i, %i, %i \n", GamePad.isUpPressed(), GamePad.isDownPressed(), GamePad.isRightPressed(), GamePad.isLeftPressed());
    // Serial.println(front);
  
  }
}