int pomiar_lewy_max = 0;
int pomiar_lewy = 0;
int pomiar_srodek = 0;
int pomiar_srodek2 = 0;
int pomiar_prawy = 0;
int pomiar_prawy_max = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);  
  pinMode(A5, INPUT);  


}

void pomiar() {
  pomiar_lewy_max = analogRead(A4);
  pomiar_lewy = analogRead(A3);
  pomiar_srodek = analogRead(A2);
  pomiar_srodek2 = analogRead(A5);
  pomiar_prawy = analogRead(A1);
  pomiar_prawy_max = analogRead(A0);
/*
  if (pomiar_lewy_max > 200){
    pomiar_lewy_max = 1;
  }
  else {
    pomiar_lewy_max = 0;
  }
  
  if (pomiar_lewy > 200){
    pomiar_lewy = 1;
  }
   else {
    pomiar_lewy = 0;
  }
  
  if (pomiar_srodek > 150){
    pomiar_srodek = 1;
  }
   else {
    pomiar_srodek = 0;
  }

  if (pomiar_srodek2 > 150){
    pomiar_srodek2 = 1;
  }
   else {
    pomiar_srodek2 = 0;
  }

  if (pomiar_prawy > 200){
    pomiar_prawy = 1;
  }
   else {
    pomiar_prawy = 0;
  }
  
  if (pomiar_prawy_max > 200){
    pomiar_prawy_max = 1;
  }
   else {
    pomiar_prawy_max = 0;
  }


*/
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
  
  delay(1000);
}
