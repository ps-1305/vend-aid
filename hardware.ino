#include <Servo.h>
#include <SoftwareSerial.h>

/*
  _   __            __    ___   _    __
 | | / /__ ___  ___/ /___/ _ | (_)__/ /
 | |/ / -_) _ \/ _  /___/ __ |/ / _  / 
 |___/\__/_//_/\_,_/   /_/ |_/_/\_,_/  

Copyright (c) 2024 Prashant Srivastav, Sahil Narkhede, Ishan Rajpurohit                                                                 
*/

// Defining our servo motor elements
Servo servo_1;
Servo servo_2;
Servo servo_3;

// pins to which arduino board will be attached
// servo motors
const int servo1Pin = 8;
const int servo2Pin = 9;
const int servo3Pin = 12;
// bluetooth modules
const int bluetoothTX = 10;
const int bluetoothRX = 11;
// temperature sensor
const int sensorPin = A0;

SoftwareSerial bluetoothModule(bluetoothTX, bluetoothRX);

// this is for running it once instead of repeatedly
bool hasRun = false;

void setup() {
  // attaching the motors to the board
  servo_1.attach(servo1Pin);
  servo_2.attach(servo2Pin);
  servo_3.attach(servo3Pin);

  // starting our input and output
  Serial.begin(9600);

  // bluetooth connection
  bluetoothModule.begin(9600);
}

void loop() {
  // if serial connection is established this loop runs
  if (Serial.available() && bluetoothModule.available() > 0) {
    // input of the character
    int input = bluetoothModule.read();

    // motor 1
    if (input == 1) {
      servo_1.attach(servo1Pin);
      hasRun = true;
      if (hasRun) {
        for (int deg = 0; deg <= 90; deg++) {
          servo_1.write(deg);
          delay(15);
        }

        for (int deg = 0; deg <= 45; deg++) {
          servo_1.write(deg);
          delay(15);
        }
        hasRun = false;
      }
    }

    // motor 2
    else if (input == 2) {
      servo_2.attach(servo2Pin);
      hasRun = true;
      if (hasRun) {
        for (int deg = 0; deg <= 90; deg++) {
          servo_2.write(deg);
          delay(15);
        }

        for (int deg = 0; deg <= 45; deg++) {
          servo_2.write(deg);
          delay(15);
        }
        hasRun = false;
      }
    }

    // motor 3
    else if (input == 3) {
      servo_3.attach(servo3Pin);
      hasRun = true;
      if (hasRun) {
        for (int deg = 0; deg <= 90; deg++) {
          servo_3.write(deg);
          delay(15);
        }

        for (int deg = 0; deg <= 45; deg++) {
          servo_3.write(deg);
          delay(15);
        }
        hasRun = false;
      }
    }

    // temperature sensor
    else if (input == 4) {
      hasRun = true;
      int sensorValue = analogRead(sensorPin);
      float voltage = sensorValue * (5.0 / 1024.0);
      float temperature = voltage * 10.0;
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" degree Celsius");
      hasRun = false;
    }

    // exit
    else if (input == 5) {
      hasRun = false;
      return;
    }
  }
  if (!hasRun) {
    servo_1.detach();
    servo_2.detach();
    servo_3.detach();
  }
}
