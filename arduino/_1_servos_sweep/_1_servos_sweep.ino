// Sweep
//demonstrating sweeping servos at the same angle 

#include <Servo.h> 

Servo myservo2;  // create servo object to control a servo 
Servo myservo3;  // create servo object to control a servo 
Servo myservo4;  // create servo object to control a servo 
Servo myservo5;  // create servo object to control a servo 
Servo myservo6;  // create servo object to control a servo 

int pos = 0;    // variable to store the servo position 

void setup() 
{ 
  myservo2.attach(2);  // attaches the servo on pin 9 to the servo object 
  myservo3.attach(3);  // attaches the servo on pin 9 to the servo object 
  myservo4.attach(4);  // attaches the servo on pin 9 to the servo object 
  myservo5.attach(5);  // attaches the servo on pin 9 to the servo object 
  myservo6.attach(6);  // attaches the servo on pin 9 to the servo object 
} 


void loop() 
{ 
  for(pos = 30; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo6.write(pos);              // tell servo to go to position in variable 'pos' 

    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 150; pos>=31; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo6.write(pos);              // tell servo to go to position in variable 'pos' 

    delay(15);                       // waits 15ms for the servo to reach the position 
  } 


} 



