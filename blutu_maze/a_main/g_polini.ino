





/*------------------po_lini-----------------
 * główna funkcja, odpowiedzialna za poruszanie sie pojazdu
 */
 

void po_lini(int czas){
  int n = czas / 30;
  n = ceil(n);
  
  for (int i = 0; i<n;i++){
   pomiar();

  if ((pomiar_prawy == 0) && (pomiar_lewy == 0) && (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0) ) {
    prosto(30);
  }

  else if ((pomiar_prawy == 1) && (pomiar_lewy == 0)&& (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0)){
    w_prawo(30);
  }

  else if ((pomiar_prawy == 0) && (pomiar_lewy == 1)&& (pomiar_lewy_max == 0) && (pomiar_prawy_max == 0)){
    w_lewo(30);
  }

  else {
    Serial.println("decyduje");
    delay(500);
    decyduj();
    delay(500);
    
    switch(mode){
      case 1:
         manewr_lewo();
      break;

      case 2:
         manewr_lewo();
      break;

      case 3:
         manewr_prawo();
      break;

      case 4:
         manewr_lewo();
      break;

      case 5:
         //jedz dalej
      break;

      case 6:
         manewr_lewo();
      break;

      case 7:
         manewr_zawroc();
      break;

      case 8:
         for( ; ; ){
          BTserial.print("HURA DOJECHALEM DO KOŃCA!");
          delay(999);
         }
      break;
     
    }
    delay(1000);
    BTserial.print("wykonałem manewr");

    }
     
  }
}
