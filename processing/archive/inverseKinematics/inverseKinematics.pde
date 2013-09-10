int segmentLength;
 
PVector shoulder;
PVector elbow;
PVector target;
 
 import processing.serial.*;
 Serial myPort;  // Create object from Serial class


void setup() {
  size(500, 500);
 
  segmentLength = int(width/5);
 
  shoulder = new PVector();
  elbow = new PVector();
  target = new PVector();
 
  shoulder.x = width/2;
  shoulder.y = height/2;
  
  String portName = Serial.list()[0];
  println(Serial.list());
  myPort = new Serial(this, portName, 9600);

}
 
void draw() {
  background(0);
 
  target.x = mouseX;
  target.y = mouseY;
 
  PVector difference = PVector.sub(target, shoulder);
  float distance = difference.mag();
 
  // don't go furthter than the full arm length
  float c = min(distance, segmentLength + segmentLength);
 
  float b = segmentLength;
  float a = segmentLength;
 
  float B = acos((a*a + c*c - b*b)/(2*a*c));
  float C = acos((a*a + b*b - c*c)/(2*a*b));
  
  // reduced form:
  //float B = acos(c/(2*a));
  //float C = acos(1 - (c*c)/(2*segmentLength*segmentLength));
 
  // angle between 
  float D = atan2(difference.y, difference.x);
  float E = D + B + PI + C; // Pi is 180 degrees in rad
 
 
 
  elbow.x = (cos(E) * segmentLength) + shoulder.x;
  elbow.y = (sin(E) * segmentLength) + shoulder.y;
 
  target.x = (cos(D+B) * segmentLength) + elbow.x;
  target.y = (sin(D+B) * segmentLength) + elbow.y;
 
 
  PVector hip = new PVector(shoulder.x, shoulder.y - 50);
 
  PVector torsoOrientation = PVector.sub(shoulder, hip);
 
  PVector upperArmOrienation = PVector.sub(elbow, shoulder);
 
  float shoulderAngle = angleBetween(shoulder, elbow, torsoOrientation);
  float elbowAngle = angleBetween(target, elbow, upperArmOrienation);
 
 
  println("s: " + shoulderAngle + "\te: " + elbowAngle);
byte out[] = new byte[2];
out[0] = byte(int(shoulderAngle));
out[1] = byte(int(elbowAngle));

myPort.write(out);
 
 stroke(255);
  fill(240, 0, 0, 200);
  ellipse(shoulder.x, shoulder.y, 20, 20);
  ellipse(elbow.x, elbow.y, 15, 15);
  ellipse(target.x, target.y, 10, 10);
  stroke(255);
  strokeWeight(2);
  line(shoulder.x, shoulder.y, elbow.x, elbow.y);
  line(elbow.x, elbow.y, target.x, target.y);
}
 
float angleBetween(PVector one, PVector two, PVector axis) {
  PVector v = PVector.sub(two, one);
  return degrees(PVector.angleBetween(v, axis));
}
