




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
int pomiary_decyduj[11][5];
      //pomiar na ktorym sie zatrzymal - przed cofnieciem
      pomiar();
      pomiary_decyduj[10][0] = pomiar_lewy_max;
      pomiary_decyduj[10][1] = pomiar_lewy;
      pomiary_decyduj[10][2] = pomiar_srodek;
      pomiary_decyduj[10][3] = pomiar_prawy;
      pomiary_decyduj[10][4] = pomiar_prawy_max;

      
cofaj(190);

for (int i =0; i<10;i++){
      pomiar();
      pomiary_decyduj[i][0] = pomiar_lewy_max;
      pomiary_decyduj[i][1] = pomiar_lewy;
      pomiary_decyduj[i][2] = pomiar_srodek;
      pomiary_decyduj[i][3] = pomiar_prawy;
      pomiary_decyduj[i][4] = pomiar_prawy_max;
      prosto(40);   
}
     

for (int i = 0; i<10; i++){
     BTserial.print(pomiary_decyduj[i][0]) ;
     BTserial.print("  ||  ");
      BTserial.print(pomiary_decyduj[i][1]) ;
     BTserial.print("  ||  ");
      BTserial.print(pomiary_decyduj[i][2]) ;
     BTserial.print("  ||  ");
      BTserial.print(pomiary_decyduj[i][3]) ;
     BTserial.print("  ||  ");
      BTserial.println(pomiary_decyduj[i][4]) ;
} 

int suma[5];
suma[0] = 0;
suma[2] = 0;
suma[4] = 0;

for (int i = 0; i<11; i++){
     suma[0] = suma[0] + pomiary_decyduj[i][0];
     suma[4] = suma[4] + pomiary_decyduj[i][4];
}


for (int i = 5; i<10; i++){
     suma[2] = suma[2] + pomiary_decyduj[i][2];
}

if ((suma[0] >0 ) && (suma[4] >0 ) &&(suma[2] >= 2) ){
  if((suma[0] >= 6) &&(suma[4] >= 6) && (suma[2] >= 3) ){
  mode = 8; //koniec trasy 
  }
  else{
  mode =1; //skrzyzowanie
  }
}

else if((suma[0] > 0) &&(suma[4] > 0) && (suma[2] <= 1) ){
  mode = 2;  // T
}

else if((suma[0] == 0) &&(suma[4] > 0) && (suma[2] <= 1) ){
  mode = 3;   // tylko prawo
}

else if((suma[0] > 0) &&(suma[4] == 0) && (suma[2] <= 1) ){
  mode = 4;   //tylko lewo
}

else if((suma[0] == 0) &&(suma[4] > 0) && (suma[2] >= 2) ){
  mode = 5;     // prosto - prawo
}

else if((suma[0] > 0) &&(suma[4] == 0) && (suma[2] >= 2) ){
  mode = 6;     // prosto - lewo
}


// z tym narazie jest taki problem ze wszystkie zera narazie sa normalna sytuacja w ktorej autko jedzie do przodu bo za czesto w srodku wywala :/
//else if((suma[0] == 0) &&(suma[4] == 0) && (suma[2] == 0) ){
//  mode = 7;     // slepa uliczka
//}



 BTserial.println("MODE:");
 BTserial.println(mode);

}
