#define A 1
#define B 2
#define C 3
#define D 4





void setup() {
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);


  

}

void loop() {
  int value = analogRead(A0);
  int val = map(value, 0, 1023, 0, 9);
  Serial.println(value);
  Serial.println(val);
  delay(1000);
 
}
