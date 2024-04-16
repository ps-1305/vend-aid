#include <Servo.h>

// Defining our servo motor elements
Servo servo_1;
Servo servo_2;
Servo servo_3;

// pins to which arduino board will be attached 
const int servo1Pin = 8;
const int servo2Pin = 9;
const int servo3Pin = 10;

// pin to which relay will be attached
const int relayPin = 11;

// pin to which temperature sensor will be attached
const int sensorPin = A0;

// this is for running it once instead of repeatedly
bool hasRun = false;

void setup(){
  // attaching the motors to the board
  servo_1.attach(servo1Pin);
  servo_2.attach(servo2Pin);
  servo_3.attach(servo3Pin);

  // starting our input and output
  Serial.begin(9600);
  // pinMode(relayPin, OUTPUT);
  // digitalWrite(relayPin, HIGH);
}

void loop(){
  // if serial connection is established this loop runs
  if(Serial.available()){
    // input of the character
    char input = Serial.read();

    if(input == 'a'){
      servo_1.attach(servo1Pin);
      hasRun = true;
      if(hasRun){
        for(int deg = 0; deg <= 90; deg++){
          servo_1.write(deg);
          delay(15);
        }

        for(int deg = 0; deg <= 45; deg++){
          servo_1.write(deg);
          delay(15);
        }
        hasRun = false;
      }
    }
    else if(input == 'b'){
      servo_2.attach(servo2Pin);
      hasRun = true;
      if(hasRun){
        for(int deg = 0; deg <= 90; deg++){
          servo_2.writfe(deg);
          delay(15);
        }

        for(int deg = 0; deg <= 45; deg++){
          servo_2.write(deg);
          delay(15);
        }
        hasRun = false;
      }
    }
    else if(input == 'c'){
      servo_3.attach(servo3Pin);
      hasRun = true;
      if(hasRun){
        for(int deg = 0; deg <= 90; deg++){
          servo_3.write(deg);
          delay(15);
        }

        for(int deg = 0; deg <= 45; deg++){
          servo_3.write(deg);
          delay(15);
        }
        hasRun = false;
      }
    }
    else if(input =='d'){
        hasRun = true;
        int sensorValue = analogRead(sensorPin);  
        float voltage = sensorValue * (5.0 / 1024.0);
        float temperature = voltage * 10.0;
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" degree Celsius");
        hasRun = false;
      }

    else if(input == 'e'){
      hasRun = false;
      return;
    }
  }
  if(!hasRun){
      servo_1.detach();
      servo_2.detach();
      servo_3.detach();
  }   
}
