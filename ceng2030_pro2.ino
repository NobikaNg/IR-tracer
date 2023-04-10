#include <Servo.h>

int LeftSensor = A4;
int RightSensor = A5;

Servo myservo;
int ServoPos=0;
int LeftStrengths=0;
int RightStrengths=0;
int DB=20;    //Dead-Band

void setup() {
  myservo.attach(11);   //attach the servo on pin 11 to the servo object
  Serial.begin(9600);
}

void loop() {
  LeftStrengths=analogRead(LeftSensor);
  RightStrengths=analogRead(RightSensor);

/* //Testing the analog value
  Serial.print(LeftStrengths);
  Serial.print(" ");
  Serial.print(RightStrengths);
  Serial.println();
  delay(1000);
  //value shows that the direction with IR has smaller value
*/

if(LeftStrengths<RightStrengths){
  //when the IR on the Left side, check the difference with dead-band
  if((RightStrengths-LeftStrengths)>DB){
    //check whether the angle > 180
    if(ServoPos > 180){
      ServoPos=180;
    }
    ServoPos--;
    myservo.write(ServoPos);
  }
}else if(RightStrengths<LeftStrengths){
  //when the IR on the right side, check the difference with dead-band
  if((LeftStrengths-RightStrengths)>DB){
    if(ServoPos<0){
      ServoPos=0;
    }
    ServoPos++;
    myservo.write(ServoPos);
  }
}
  delay(30);
}
