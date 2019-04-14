int licznik = 0;

void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(8,INPUT);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  Serial.begin(9600);

}

void loop() {
  Serial.println(licznik);
  
  if(digitalRead(8) == LOW)
  {
    licznik++;
  }
  
  delay(1005);
  
 /*  if(licznik >= 6)
    {
      digitalWrite(3,HIGH);      
    }
    else if(licznik >= 4)
    {
      digitalWrite(2,HIGH);
    }
    else if(licznik >= 2);
    {
      digitalWrite(1,HIGH);
    }
*/
}
