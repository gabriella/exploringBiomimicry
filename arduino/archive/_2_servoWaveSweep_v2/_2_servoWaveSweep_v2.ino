
//code to move servos in a line in a wave like formation
//written by gabriella levine for itp 2013 exploring biomimicry, sine example

#include <Servo.h>
const int ledpin = 13;
int servosPins[] = {
  2,3,4,5,6};
//int servoValues[] = {
//  20, 50, 80,110,140};

int servoValues[] = {
  90, 100, 110,120,130};
  
const int NUM_SERVOS = 6;
Servo servos[NUM_SERVOS];
const int FIRST_SERVO_PIN=2;//to prevent base servo from rotating

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


  lastUpdatedAt = millis();
  Serial.println("starting");
}

void loop(){
  //Serial.println(millis());

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

    // int myNewFirstValue = 90; //how ever you're calculating this
    //passDownServoValues(myNewFirstValue);
    //after  your servoValues array is correct
    //adjustServos();

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


    //passDownServoValues(nextServoValue);
    lastUpdatedAt = millis();
  }

  updateServos();

}

void passDownServoValues(int firstValue){
  // {100, 50, 1, 23, 17, 100};
  // {firstVAlue, 100, 50, 1, 23, 17}
  // {90, 90, 90}
  // {0, 0, 90}
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
    // passDownServoValues(myValue);
    // Serial.println("passing down");
    passDownServoValues(nextServoValue);

  }



}

//send values from xbee
//get one wave to start then stop
//bigger jump between steps



