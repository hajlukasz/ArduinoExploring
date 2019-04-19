void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);

}

void loop() {

  if(digitalRead(8) == LOW) {
     digitalWrite(1, HIGH);
     delay(5000);  
     digitalWrite(1, LOW); 
     digitalWrite(2, HIGH);
     delay(5000);
     digitalWrite(2, LOW); 
     digitalWrite(3, HIGH);
     delay(5000);
     digitalWrite(2, HIGH);
     delay(2000);
     digitalWrite(2, LOW);
     digitalWrite(3, LOW);
     digitalWrite(1, HIGH); 
     delay(1000);
     digitalWrite(1, LOW); 
     
     
  }

  else {
     digitalWrite(2, HIGH);
     delay(500);
     digitalWrite(2, LOW);
     delay(500);
  }


}
