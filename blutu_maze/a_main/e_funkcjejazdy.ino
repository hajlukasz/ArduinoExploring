






// ----------------------90 stopni w lewo------------------------

void manewr_lewo(){
  
    //  Serial.print("90 w lewo");
              w_lewo(400);
      prosto(250);
       w_lewo(350);
    
     
      do{
         pomiar();
         w_lewo(20);
          BTserial.println("_troche w lewo");
      }while(pomiar_srodek == 0);      
}







// --------------------------90 stopni w prawo----------------------

void manewr_prawo(){
  
    //  Serial.print("90 w lewo");
     w_prawo(250);
  prosto(120);
      do{
         pomiar();
         w_prawo(23);
          BTserial.print("_troche w prawo");
          //delay();
      }while(pomiar_srodek ==0);      
}




// --------------------zawracanie-----------------------------------------

void manewr_zawroc(){
  
  
  do{
         pomiar();
         cofaj(200);
         w_prawo(200);
         w_prawo(40);
          BTserial.print("_troche w prawo");
          delay(20);
      }while(pomiar_srodek ==0);  
}


//-------------------------------------------------------------------

void prosto(int czas){
  //silnik lewy
 
  digitalWrite(In1, HIGH);
  digitalWrite(In3, HIGH);
  
  delay(czas);
  
  digitalWrite(In1, LOW);
  digitalWrite(In3, LOW);
}



//-------------------------------------------------------------------

void cofaj(int czas){
  //silnik lewy
 
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
