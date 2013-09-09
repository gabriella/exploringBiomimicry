
//code to move servos in a line in a wave like formation
//written by gabriella levine for itp 2013 exploring biomimicry, sine example

#include <Servo.h>
const int ledpin = 13;
int servosPins[] = {
  2,3,4,5,6};
//int servoValues[] = {
//  20, 50, 80,110,140};

int servoValues[] = {
  40, 50, 60,70,80};

const int NUM_SERVOS = 5;
Servo servos[NUM_SERVOS];
const int FIRST_SERVO_PIN=2;

int nextServoValue = 120;

int currentServo = 0;

const int UPDATE_INTERVAL = 1000;

long lastUpdatedAt = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  //setup all your servos;
  for(int i=0;i<NUM_SERVOS;i++)
    servos[i].attach(FIRST_SERVO_PIN +i);
  // or you can do it like this:
  // servos[0].attach(2);
  //  servos[1].attach(3);.....

  lastUpdatedAt = millis();
  Serial.println("starting");
}

void loop(){
  //Serial.println(millis());
//if you want to send it values from xbee or serial
  if(Serial.available()>0){
    digitalWrite(13, HIGH);
    /* byte inByte =Serial.read();
     //int inByte = Serial.parseInteger();
     //Serial.println(inByte);
     if(inByte == 50||inByte==51){
     nextServoValue=nextServoValue+1;
     Serial.println("up");
     }
     else if(inByte==49||inByte==52){
     nextServoValue = nextServoValue-1;
     ; 
     Serial.println("down");
     }
     if(nextServoValue > 140){
     nextServoValue = 140;
     }
     else if(nextServoValue<60){
     nextServoValue = 60; 
     }
     Serial.println(nextServoValue);
     */
  }

  if(millis() - lastUpdatedAt  > UPDATE_INTERVAL){
    Serial.println();

    loopServos();
    Serial.print("0: ");
    Serial.print(servoValues[0]);
    Serial.print(" \t1: ");
    Serial.print(servoValues[1]); 
    Serial.print(" \t2: ");
    Serial.print(servoValues[2]);
    Serial.print(" \t3: ");
    Serial.print(servoValues[3]);
    Serial.print(" \t4: ");
    Serial.print(servoValues[4]);
    lastUpdatedAt = millis();
  }

  updateServos();

}

void passDownServoValues(int firstValue){
  for(int i = NUM_SERVOS-1; i > 0; i--){// cant write servoValues.length
    servoValues[i] = servoValues[i-1];
  }

  servoValues[0] = firstValue;
}

void updateServos(){
  for(int i =0; i < NUM_SERVOS; i++){
    servos[i].write(servoValues[i]);
  }
}

void loopServos(){
  passDownServoValues(servoValues[NUM_SERVOS-1]);
}

void adjustServos(){
  // update the current servo

  servos[currentServo].write(servoValues[currentServo]);

  currentServo++;
  if(currentServo > NUM_SERVOS-1){
    currentServo = 0;
    passDownServoValues(nextServoValue);

  }

}





