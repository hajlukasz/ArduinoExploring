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

void po_lini(int czas){
  int n = czas / 30;
  n = ceil(n);
  
  for (int i = 0; i<n;i++){
   pomiar();



  if ((pomiar_prawy < 150) && (pomiar_lewy <150)) {
    prosto(30);
  }

  else if ((pomiar_prawy >150) && (pomiar_lewy <150)){
    w_prawo(30);
  }

  else if ((pomiar_prawy < 150) && (pomiar_lewy > 150)){
    w_lewo(30);
  }

  else {
    digitalWrite(2,HIGH);
  }
     
  }
}

void cofaj(int czas){
  //silnik lewy
 
  digitalWrite(In2, HIGH);
  digitalWrite(In4, HIGH);
  
  delay(czas);
  
  digitalWrite(In2, LOW);
  digitalWrite(In4, LOW);
}

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
  digitalWrite(In2, LOW);
  digitalWrite(In4, HIGH);
  
  delay(czas);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In4, LOW);
}

void w_prawo (int czas){
  digitalWrite(In3, HIGH);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In4, LOW);

  delay(czas);

  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In4, LOW);
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
  analogWrite(EnA,150);
  analogWrite(EnB,185);
  
  
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
    
    Serial.println(inputString.toInt());
    int spr = inputString.toInt();
    int czas = 0;
    if (spr < 1000){
      czas  = spr;
      Serial.println("prosto");
      Serial.println(czas);
      prosto(czas);
      
    }
    else if (spr >= 1000 && spr <2000){
      czas = spr - 1000;
      Serial.println("prawo");
      Serial.println(czas);
      w_prawo(czas);
      
    }
    else if (spr >= 2000 && spr <3000){
      czas = spr - 2000;
      Serial.println("lewo");
      Serial.println(czas);
      w_lewo(czas);
      
    }
    else if (spr >= 3000 && spr <4000){
        czas = spr - 3000;
      Serial.println("lewo");
      Serial.println(czas);
      cofaj(czas);
      
    }

     else if (spr >= 4000 && spr <6000){
        czas = spr - 4000;
      Serial.println("following");
      Serial.println(czas);
      po_lini(czas);
      
    }
   
    // clear the string:
    inputString = "";
    stringComplete = false;
}
  
  delay(1000);
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
