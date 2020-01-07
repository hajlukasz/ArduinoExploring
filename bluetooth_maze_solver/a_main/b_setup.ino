






void setup(){
  Serial.begin(9600);
  BTserial.begin(9600);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);  
  pinMode(A5, INPUT);  
  analogWrite(EnA,180);
  analogWrite(EnB,150);
  
  BTserial.println("hej, czekaj na kalibracje");
  kalibracja();

}
