#define EnA 10
#define EnB 5
#define In2 8
#define In1 9
#define In4 6
#define In3 7
int pomiar_lewy_max = 0;
int pomiar_lewy = 0;
int pomiar_srodek = 0;
int pomiar_srodek2 = 0;
int pomiar_prawy = 0;
int pomiar_prawy_max = 0;
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete


void prosto(int czas){
  //silnik lewy
 
  digitalWrite(In1, HIGH);
  digitalWrite(In3, HIGH);
  
  delay(czas);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}

void w_lewo (int czas){
  digitalWrite(In1, HIGH);
  digitalWrite(In3, LOW);
  
  delay(czas);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}

void w_prawo (int czas){
  digitalWrite(In3, HIGH);
  digitalWrite(In1, LOW);

  delay(czas);

  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}

void setup() {
  // put your setup code here, to run once:

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
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);  
  pinMode(A5, INPUT);  
  inputString.reserve(200);

}

void pomiar() {
  pomiar_lewy_max = analogRead(A4);
  pomiar_lewy = analogRead(A3);
  pomiar_srodek = analogRead(A2);
  pomiar_srodek2 = analogRead(A5);
  pomiar_prawy = analogRead(A1);
  pomiar_prawy_max = analogRead(A0);

}
void loop() {
  // put your main code here, to run repeatedly:
  prosto(10);
  pomiar();
  Serial.print("LEWY > >   ");
  Serial.print(pomiar_lewy_max);
  Serial.print("  || ");
  Serial.print(pomiar_lewy);
  Serial.print("  || ");
  //Serial.print(pomiar_srodek);
  Serial.print(pomiar_srodek2);
  Serial.print("  || ");
  Serial.print(pomiar_prawy);
  Serial.print("  || ");
  Serial.print(pomiar_prawy_max);
  Serial.println("  < < PRAWY");
  Serial.println("_____________________________________________________________");

  
  if (stringComplete) {
    
    Serial.println(inputString);
    prosto(inputString.toInt());
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
  delay(100);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}