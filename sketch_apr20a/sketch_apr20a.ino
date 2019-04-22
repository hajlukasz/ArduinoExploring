#define EnA 5   //lewy
#define EnB 10  // prawy
#define In1 6   // lewy ?
#define In2 7   // lewy przod
#define In3 8   //prawy tył
#define In4 9   //prawy przod
void setup() {
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  analogWrite(EnA,150);
  analogWrite(EnB,155);
  
}

void loop() {
  digitalWrite(In2,HIGH);
  digitalWrite(In4,HIGH);
  // put your main code here, to run repeatedly:

}
