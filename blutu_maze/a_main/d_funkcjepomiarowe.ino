






/*-----------------------------pomiar---------------------------
 * pomiar pieciu wartosci analogowy z czujnikow i przerobienie 
 * ich na 0 i 1 korzystajac z wczesniejszej kalibracji
 */
 
void pomiar() {
  
  pomiar_lewy_max = analogRead(A4);
  pomiar_lewy = analogRead(A3);
  pomiar_srodek = analogRead(A5);
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









/*----------------------pomiar_print-----------------------------
 * pozwala wyisac ładnie analogowe odczyty
 */

 
void pomiar_print(){
  
  pomiar_lewy_max = analogRead(A4);
  pomiar_lewy = analogRead(A3);
  pomiar_srodek = analogRead(A5);
  pomiar_prawy = analogRead(A1);
  pomiar_prawy_max = analogRead(A0);  
  BTserial.print("LEWY > >   ");
  BTserial.print(pomiar_lewy_max);
  BTserial.print("  || ");
  BTserial.print(pomiar_lewy);
  BTserial.print("  || ");
  BTserial.print(pomiar_srodek);
  BTserial.print("  || ");
  BTserial.print(pomiar_prawy);
  BTserial.print("  || ");
  BTserial.print(pomiar_prawy_max);
  BTserial.println("  < < PRAWY");
  BTserial.println("_____________________________________________________________");
}






/*-------------------kalibracja---------------------
 * jako że używam odczytów analogowych potrzebuje stowrzyc sobie skale
 * kiedy przyjac 0 a kiedy 1 w zaleznosci od podloza 
 ---------------------------------------------------- */
 
void kalibracja() {

  int roznica = 135;                //zmien jesli chcesz zeby łapał jedynke przy wiekszej zmianie
  int pomiary_kalibracja[9][4];   //tablica na potrzebne pomiary

 while(kalibracja_lewy_max > 800 || kalibracja_lewy > 800 || kalibracja_srodek > 800 || kalibracja_prawy > 800 || kalibracja_prawy_max > 800){              //petla z takimi warunnkami zeby mi nie wyszla głupota [case np jak stoi jednym czujnikiem przypadkiem na lini zamiast na podłozu]
  
    for (int i =0;i<10; i++){
      pomiar_lewy_max = analogRead(A4);
      pomiar_lewy = analogRead(A3);
      pomiar_srodek = analogRead(A5);
      pomiar_prawy = analogRead(A1);
      pomiar_prawy_max = analogRead(A0);  
      pomiary_kalibracja[i][0] = pomiar_lewy_max;
      pomiary_kalibracja[i][1] = pomiar_lewy;
      pomiary_kalibracja[i][2] = pomiar_srodek;
      pomiary_kalibracja[i][3] = pomiar_prawy;
      pomiary_kalibracja[i][4] = pomiar_prawy_max;
      delay(50);   
    };

    int suma[5] = {0,0,0,0,0};
    
    for (int i = 0; i<10; i++){
       suma[0] = pomiary_kalibracja[i][0] + suma[0];
       suma[1] = pomiary_kalibracja[i][1] + suma[1];
       suma[2] = pomiary_kalibracja[i][2] + suma[2];
       suma[3] = pomiary_kalibracja[i][3] + suma[3];
       suma[4] = pomiary_kalibracja[i][4] + suma[4];
     }

    kalibracja_lewy_max = suma[0] / 10 + roznica;
    kalibracja_lewy = suma[1] /10 + roznica;
    kalibracja_srodek = suma[2] /10+ roznica - 35; //odjalem bo srodek jest kluczowy w slepych uliczkach
    kalibracja_prawy = suma[3] /10+ roznica;
    kalibracja_prawy_max = suma[4] /10+ roznica;
    
  }

  BTserial.println("skalibrowano!");
}





/*------------logika--------------------
 * potrzebna przy manewrach do zatrzymania obrotu w takim ustawieniu czujników 
 * z jakiego moze potem dalej normalnie ruszyc
 * 
 ------------------------------------------------*/
bool logika(){
  if((pomiar_prawy == 0) && (pomiar_lewy == 1) && (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0) && (pomiar_srodek == 0 || pomiar_srodek == 1)){
    return 0;
  }

  else if ((pomiar_prawy == 1) && (pomiar_lewy == 0) && (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0) && (pomiar_srodek == 0 || pomiar_srodek == 1)){
    return 0;
  }

  else if ((pomiar_prawy == 0) && (pomiar_lewy == 0) && (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0) && (pomiar_srodek == 1)){
    return 0;
  }

  else{
    return 1;
  }
}
