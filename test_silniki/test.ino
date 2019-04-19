#define EnA 10
#define EnB 5
#define In2 8
#define In1 9
#define In4 6
#define In3 7


void setup() {
  Serial.begin(9600);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(11, INPUT);

   analogWrite(EnA, 180);
     analogWrite(EnB, 180);

}

void loop() {
  digitalWrite(In4, LOW);
  digitalWrite(2, HIGH);
  delay(1700);
  digitalWrite(2, LOW);
  digitalWrite(In1, HIGH);
   digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  delay(1000);
  digitalWrite(In1, LOW);
   digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  delay(1000);
  digitalWrite(In1, LOW);
   digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  delay(1000);
  digitalWrite(In1, LOW);
   digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  delay(1000);
}
