//--------- pomiar 
void pomiar() {
  
  pomiar_lewy_max = analogRead(A4);
  pomiar_lewy = analogRead(A3);
  pomiar_srodek = analogRead(A2);
  pomiar_srodek2 = analogRead(A5);
  pomiar_prawy = analogRead(A1);
  pomiar_prawy_max = analogRead(A0);
  
}

/*-------------------kalibracja---------------------
 * jako że używam odczytów analogowych potrzebuje stowrzyc sobie skale
 * kiedy przyjac 0 a kiedy 1 w zaleznosci od podloza 
 ---------------------------------------------------- */
 
void kalibracja() {

int lewy_suma = 0,lewy_srednia =0,prawy_suma=0,prawy_srednia=0;

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
}
