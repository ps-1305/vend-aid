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
          servo_2.write(deg);
          delay(15);
        }

        for(int deg = 0; deg <= 45; deg++){
          servo_2.write(deg);
          delay(15);
        }
        hasRun = false;
      }
