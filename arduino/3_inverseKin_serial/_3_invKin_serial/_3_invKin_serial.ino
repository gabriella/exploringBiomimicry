#include <Servo.h>

//Declares the servos.
Servo shoulder;
Servo elbow;


//Setup servo positions.
int nextServo = 0;
int servoAngles[] = {0, 0};

//Define pins for each servo.
void setup()
{
  shoulder.attach(3);
  elbow.attach(4);
 
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0)
  {
    int servoAngle = Serial.read();  
    
    servoAngles[nextServo] = servoAngle;  
    nextServo++;  
   
    if(nextServo > 1)
    {
      nextServo = 0;  
    }

    shoulder.write(servoAngles[0]);
    elbow.write(servoAngles[1]);
    
  }
}
