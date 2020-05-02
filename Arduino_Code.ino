#include <Servo.h>
#define EN 8
#define Dir 5
#define Step 2
#define In 10

String input;
Servo servo;

void setup() {
 pinMode(EN, OUTPUT);
 pinMode(Dir, OUTPUT);
 pinMode(Step, OUTPUT);
 pinMode(In, INPUT);
servo.attach(9);
input = "";


}

void loop() {
  if (Serial.available()){
  input = Serial.readString();
   }
   if(input == "fast"){
        Turn(500);
    } else if(input == "normal"){
        Turn(1000);
    }else if(input == "reset"){
        setzero();
    }

}


void Turn(int Delay){
    for(int i=0; i<200; i++){
        digitalWrite(Step, HIGH);
        delayMircoseconds(Delay);
        digitalWrite(Step, LOW);
        delayMircoseconds(Delay);
    }
}

void setzero(){
    servo.write(180);
    while(digitalRead(10) != HIGH){
        digitalWrite(Step, HIGH);
        delayMircoseconds(500);
        digitalWrite(Step, LOW);
        delayMircoseconds(500);
    }
    servo.write(0);
}


