#include <Servo.h>
Servo servo;

int angle = 100;

void setup() {
  servo.attach(7);
  servo.write(angle);
}

void loop() 
{ 
  
}
