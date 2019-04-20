


/*------------------po_lini-----------------
 * główna funkcja, odpowiedzialna za poruszanie sie pojazdu
 */
 
void po_lini(int czas){
  int n = czas / 30;
  n = ceil(n);
  
  for (int i = 0; i<n;i++){
   pomiar();

  if ((pomiar_prawy == 0) && (pomiar_lewy == 0) && (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0)) {
    prosto(30);
  }

  else if ((pomiar_prawy == 1) && (pomiar_lewy == 0)&& (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0)){
    w_prawo(30);
  }

  else if ((pomiar_prawy == 0) && (pomiar_lewy == 1)&& (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0)){
    w_lewo(30);
  }

  else {
    
  }
   //else if (((pomiar_prawy == 1) && (pomiar_lewy == 1)) || pomiar_lewy_max == 1 || pomiar_prawy_max == 1 ){
  //  w_lewo(30);
  //}
     
  }
}






/*---------------decyduj--------------------
 * po zauważeniu przez robota zdarzerzenia innego niz linia, przejezdza odpowiednia droge 
 * i do zmiennej mode wpisuje w zaleznosci od napotkaniej przeszkody
 * [ 0 = zwykla linia ]
 * 1 = skrzyzowanie (linie prawo lewo i posrodku
 * 2 = T (linie prawo lewo)
 * 3 = tylko prawo
 * 4 = tylko lewo
 * 5 = prosto/prawo
 * 6 = prosto lewo
 * 7 = slepa uliczka
 * 8 = koniec trasy
 * 
 */
void decyduj(){
int pomiary_decyduj[10][5];

for (int i =0; i<10;i++){
      pomiar();
      pomiary_decyduj[i][0] = pomiar_lewy_max;
      pomiary_decyduj[i][1] = pomiar_lewy;
      pomiary_decyduj[i][2] = pomiar_srodek;
      pomiary_decyduj[i][3] = pomiar_prawy;
      pomiary_decyduj[i][4] = pomiar_prawy_max;
      prosto(30);   
}
     

for (int i = 0; i<10; i++){
     Serial.print(pomiary_decyduj[i][0]) ;
     Serial.print("  ||  ");
      Serial.print(pomiary_decyduj[i][1]) ;
     Serial.print("  ||  ");
      Serial.print(pomiary_decyduj[i][2]) ;
     Serial.print("  ||  ");
      Serial.print(pomiary_decyduj[i][3]) ;
     Serial.print("  ||  ");
      Serial.println(pomiary_decyduj[i][4]) ;
}

int suma[5];

for (int i = 0; i<10; i++){
     suma[0] = suma[0] + pomiary_decyduj[i][0];
     suma[4] = suma[4] + pomiary_decyduj[i][4];
}

for (int i = 7; i<10; i++){
     suma[2] = suma[2] + pomiary_decyduj[i][2];
}

if ((suma[0] >=2 ) && (suma[4] >=2 ) &&(suma[2] >= 1) ){
 mode =1;    //skrzyzowanie
}

else if((suma[0] >= 2) &&(suma[4] >=2) && (suma[2] == 0) ){
  mode = 2;  // T
}

else if((suma[0] < 2) &&(suma[4] >= 2) && (suma[2] == 0) ){
  mode = 3;   // tylko prawo
}

else if((suma[0] >= 2) &&(suma[4] < 2) && (suma[2] ==0) ){
  mode = 4;   //tylko lewo
}

else if((suma[0] < 2) &&(suma[4] >= 2) && (suma[2] >= 1) ){
  mode = 5;     // prosto - prawo
}

else if((suma[0] >= 2) &&(suma[4] < 2) && (suma[2] >= 1) ){
  mode = 6;     // prosto - lewo
}

else if((suma[0] == 0) &&(suma[4] == 0) && (suma[2] == 0) ){
  mode = 7;     // slepa uliczka
}

else if((suma[0] >= 9) &&(suma[4] >= 9) && (suma[2] >= 2) ){
  mode = 8;     // koniec trasy
}
 Serial.println("MODE:");
 Serial.println(mode);

}

void manewr_lewo(){
  
    //  Serial.print("90 w lewo");
      prosto(300);
      w_lewo(350);
      do{
         pomiar_srodek = analogRead(A5);
         w_lewo(30);
          Serial.print("_troche w lewo");
      }while(pomiar_srodek ==0);      
}


void manewr_prawo(){
  
    //  Serial.print("90 w lewo");
      prosto(300);
      w_prawo(200);
      do{
         pomiar();
         w_prawo(30);
          Serial.print("_troche w prawo");
          delay(20);
      }while(pomiar_srodek ==0);      
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
