#define EnA 10
#define EnB 5
#define In2 8
#define In1 9
#define In4 6
#define In3 7
int pomiar_lewy = 0;
int pomiar_prawy = 0;
int lewy_kalibracja =1023;
int prawy_kalibracja = 1023;

void pomiar() {
  pomiar_prawy = analogRead(A1);
  pomiar_lewy = analogRead(A3);
}

void prosto(){
  //silnik lewy
 
  digitalWrite(In1, HIGH);
  //silnik prawy

  digitalWrite(In3, HIGH);
  delay(20);
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}

void w_lewo (){
  digitalWrite(In1, HIGH);
  digitalWrite(In3, LOW);
  
  delay(30);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}

void w_prawo (){
  digitalWrite(In3, HIGH);
  digitalWrite(In1, LOW);

  delay(30);

  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}



void setup() {
 // Serial.begin(9600);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A1, INPUT);
  pinMode(11, INPUT);

  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(2, LOW);
analogWrite(EnA, 150);
    analogWrite(EnB, 150);
  
  int lewy_suma = 0,lewy_srednia =0,prawy_suma=0,prawy_srednia=0;
  
  delay(1500);

//kalibracja

while(lewy_kalibracja >1000 || prawy_kalibracja>1000){
  lewy_suma = 0,lewy_srednia =0,prawy_suma=0,prawy_srednia=0;
  
  for (int i =0;i<10; i++){
    pomiar();
    lewy_suma = pomiar_lewy + lewy_suma;
    prawy_suma = pomiar_prawy + prawy_suma;
    delay(50);   
  };

  lewy_srednia = lewy_suma/10;
  prawy_srednia = prawy_suma/10;

  //Serial.print("prawy srednia");
  //Serial.println(prawy_srednia);
    
  //Serial.print("lewy srednia");
  //Serial.println(lewy_srednia);

  lewy_kalibracja = lewy_srednia + 250;
  prawy_kalibracja = prawy_srednia + 250;
  
}

  digitalWrite(2, HIGH); // kalibracja udana
  
// zapalnik
/*
  int start = 0;
  
while(start == 0){
  start = digitalRead(11);
  Serial.print("start");
  Serial.println(start);
  delay(50);
}

*/
// sygnalizacja startu za jakas sekunde

for(int i =0;i<5;i++){
  digitalWrite(2, LOW);
  delay(300);
  digitalWrite(2, HIGH);
  delay(300);
}

delay(1000);


}

void loop() {
  pomiar();

  Serial.print("prawy");
  Serial.println(pomiar_prawy);
    
  Serial.print("lewy");
  Serial.println(pomiar_lewy);

  if ((pomiar_prawy < prawy_kalibracja) && (pomiar_lewy <lewy_kalibracja)) {
    prosto();
  }

  else if ((pomiar_prawy > prawy_kalibracja) && (pomiar_lewy <lewy_kalibracja)){
    w_prawo();
  }

  else if ((pomiar_prawy < prawy_kalibracja) && (pomiar_lewy > lewy_kalibracja)){
    w_lewo();
  }

  else {
   
  digitalWrite(In1, HIGH);
  //silnik prawy

  digitalWrite(In3, HIGH);
  delay(10);
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  }
}
