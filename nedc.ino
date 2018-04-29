
#include <Servo.h>


int leftServoPin = 9;
Servo left;

int rightServoPin = 11;
Servo right;

int leftLightPin = 0;

int rightLightPin = 5;


void setup() {
    Serial.begin(9600);
    left.attach(leftServoPin);
    right.attach(rightServoPin);
}

void loop() {
    int leftLightValue = analogRead(leftLightPin);
    int rightLightValue = analogRead(rightLightPin);

    int num = leftLightValue-rightLightValue;
    
    if(num<-30){
      num = (-1)*num;
      Serial.println(num);
      num = map(num,30,300,30,160);
      
      left.write(num);
      right.write(170-num);    
    }else if(num>30){
      Serial.println(num);
      num = map(num,30,300,30,160);
      left.write(170-num);
      right.write(num);  
    }
    delay(750);
    
    
    
    
}




