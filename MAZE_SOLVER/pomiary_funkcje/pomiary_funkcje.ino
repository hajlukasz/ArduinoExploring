#define EnA 10
#define EnB 5
#define In2 8
#define In1 9
#define In4 6
#define In3 7
int pomiar_lewy_max = 0;
int pomiar_lewy = 0;
int pomiar_srodek = 0;
int pomiar_prawy = 0;
int pomiar_prawy_max = 0;
int kalibracja_lewy_max =1023;
int kalibracja_lewy =1023;
int kalibracja_prawy =1023;
int kalibracja_prawy_max =1023;
int kalibracja_srodek =1023;


//setup________________________________
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
//__________________________________________________________________________________________


/*--------- pomiar_analog---------------- 
 * pomiar pieciu wartosci analogowy z czujnikow i przerobienie 
 * ich na 0 i 1 korzystajac z wczesniejszej kalibracji
 */
void pomiar() {
  
  pomiar_lewy_max = analogRead(A4);
  pomiar_lewy = analogRead(A3);
  pomiar_srodek = analogRead(A2);
  pomiar_srodek2 = analogRead(A5);
  pomiar_prawy = analogRead(A1);
  pomiar_prawy_max = analogRead(A0);  

   if (pomiar_lewy_max > kalibracja_lewy_max){
    pomiar_lewy_max = 1;
  }
  else {
    pomiar_lewy_max = 0;
  }

  
  if (pomiar_lewy > kalibracja_lewy){
    pomiar_lewy = 1;
  }
   else {
    pomiar_lewy = 0;
  }

  
  if (pomiar_srodek > kalibracja_srodek){
    pomiar_srodek = 1;
  }
   else {
    pomiar_srodek = 0;
  }


  if (pomiar_prawy > kalibracja_prawy){
    pomiar_prawy = 1;
  }
   else {
    pomiar_prawy = 0;
  }
  
  if (pomiar_prawy_max > kalibracja_prawy_max){
    pomiar_prawy_max = 1;
  }
   else {
    pomiar_prawy_max = 0;
  }

}




/*-------------------kalibracja---------------------
 * jako że używam odczytów analogowych potrzebuje stowrzyc sobie skale
 * kiedy przyjac 0 a kiedy 1 w zaleznosci od podloza 
 ---------------------------------------------------- */
 
void kalibracja() {

  int roznica = 150                //zmien jesli chcesz zeby łapał jedynke przy wiekszej zmianie
  int pomiary_kalibracja[9][4];   //tablica na potrzebne pomiary

  while(kalibracja_lewy_max > 800 || kalibracja_lewy > 800 || kalibracja_srodek > 800 || kalibracja_prawy > 800 || kalibracja_prawy_max > 800){              //petla z takimi warunnkami zeby mi nie wyszla głupota [case np jak stoi jednym czujnikiem przypadkiem na lini zamiast na podłozu]
  
    int suma[4],srednia[4];
  
    for (int i =0;i<10; i++){
      pomiar();
      lewy_suma = pomiar_lewy + lewy_suma;
      prawy_suma = pomiar_prawy + prawy_suma;
      delay(50);   
    };

    lewy_srednia = lewy_suma/10;
    prawy_srednia = prawy_suma/10;


    lewy_kalibracja = lewy_srednia + 250;
  prawy_kalibracja = prawy_srednia + 250;
  
}
}
