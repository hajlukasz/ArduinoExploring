void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading = analogRead(A0);
  if (sensorReading < 400) {
    Serial.println("RAINING");
  }
  Serial.println(sensorReading);
  delay(150);
}
