






// ----------------------90 stopni w lewo------------------------

void manewr_lewo(){
  
  w_lewo(300);
  prosto(200);
           
  do{
    pomiar();
    w_lewo(30);
    //BTserial.println("_troche w lewo");
  }while(logika());       
}







// --------------------------90 stopni w prawo----------------------

void manewr_prawo(){
  
  w_prawo(250);
  prosto(220);
  
  do{
    pomiar();
    w_prawo(30);
    //BTserial.print("_troche w prawo");
  }while(logika());      // kreci sie dopoki nie usyska tego co chcemy 
}




// --------------------zawracanie-----------------------------------------

void manewr_zawroc(){
  
  w_prawo(300);
  do{
    pomiar();
    w_prawo(30);
    //BTserial.print("_troche w prawo");
    //delay(20);
    }while(logika() );  
}


//-------------------------------------------------------------------

void prosto(int czas){
 
  digitalWrite(In1, HIGH);
  digitalWrite(In3, HIGH);
  
  delay(czas);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}



//-------------------------------------------------------------------

void cofaj(int czas){

  digitalWrite(In2, HIGH);
  digitalWrite(In4, HIGH);
  
  delay(czas);
  
  digitalWrite(In2, LOW);
  digitalWrite(In4, LOW);
}



//-------------------------------------------------------------------

void w_prawo (int czas){
  
  digitalWrite(In2, HIGH);
  digitalWrite(In1, LOW);
  digitalWrite(In4, LOW);
  digitalWrite(In3, HIGH);
  
  delay(czas);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In4, LOW);
}





//-------------------------------------------------------------------

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




// ----------------------wysrodkowanie z lekkim cofnieciem do tyłu------------------------ 
// jeszczeni nie próbowałem jakby z tym dzialalo i czy to wgl jest potrzebne czy nie lepiej zoptymalizowac decyduj jakos


void wysrodkuj(){
     
      cofaj(100);
      do{
         pomiar();
          if ((pomiar_lewy == 0) && (pomiar_srodek == 0) && (pomiar_prawy == 0)){
          w_lewo(30);
          }

          else if ((pomiar_lewy == 0) && (pomiar_srodek == 0) && (pomiar_prawy == 1)){
          w_lewo(30);
          }

          else if ((pomiar_lewy == 0) && (pomiar_srodek == 1) && (pomiar_prawy == 0)){
          w_lewo(30);
          }

          else if ((pomiar_lewy == 0) && (pomiar_srodek == 1) && (pomiar_prawy == 1)){
          w_lewo(30);
          }

          else if ((pomiar_lewy == 1) && (pomiar_srodek == 0) && (pomiar_prawy == 0)){
          w_lewo(30);
          }

          else if ((pomiar_lewy == 1) && (pomiar_srodek == 0) && (pomiar_prawy == 1)){
          w_lewo(30);
          }

          else if ((pomiar_lewy == 1) && (pomiar_srodek == 1) && (pomiar_prawy == 0)){
          w_lewo(30);
          }

          else if ((pomiar_lewy == 1) && (pomiar_srodek == 1) && (pomiar_prawy == 1)){
          w_lewo(30);
          }
     
      }while(!(pomiar_srodek == 1 && pomiar_prawy == 0 && pomiar_lewy == 0));      
}





/* ----------------------cofaj po lini------------------------

void cofaj_polini(){
  
  while(){
    
  if ((pomiar_prawy == 0) && (pomiar_lewy == 0) && (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0) ) {
    prosto(30);
  }

  else if ((pomiar_prawy == 1) && (pomiar_lewy == 0)&& (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0)){
    w_prawo(30);
  }

  else if ((pomiar_prawy == 0) && (pomiar_lewy == 1)&& (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0)){
    w_lewo(30);
  }
  
  }
}

*/
