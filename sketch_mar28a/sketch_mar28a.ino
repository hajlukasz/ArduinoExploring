int pomiar0 = 0;
int pomiar1 = 1;

void setup () {
    Serial.begin(9600); 
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}


void loop () {
    pomiar0 = analogRead(A0);
    pomiar1 = analogRead(A1);
    Serial.print("A0:");
    Serial.println(pomiar0);
    
    Serial.print("A1:");
    Serial.println(pomiar1);
    delay(1000);
}
