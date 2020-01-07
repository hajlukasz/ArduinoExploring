





/*------------------po_lini-----------------
 * główna funkcja, odpowiedzialna za poruszanie sie pojazdu
 */
 

void po_lini(int czas){
  
    stringComplete = false;
    inputString = "";
    int i =0;
    do{ 
      
    switch(mode){
      case 0:
            pomiar();

            if ((pomiar_lewy == 0) && (pomiar_lewy_max == 0) && (pomiar_srodek == 1) && (pomiar_prawy == 0) &&(pomiar_prawy_max == 0)) {
              prosto(30);
              i =0;
              BTserial.print("^");
              BTserial.print(i);
            }

            else if ((pomiar_lewy == 0) && (pomiar_lewy_max == 0) && ( pomiar_srodek == 0) && (pomiar_prawy == 0) &&(pomiar_prawy_max == 0)){
              i += 1;
              if (i > 20){      //czasem randomowo srodek nie pokazuje dlatego zeby poradzic sobie z problem rozpoznawania slepej uliczki 
                cofaj(250);
                mode = 7;       //wymyslilem cos takiego co stwierdza ze jestes w slepiej uliczce jak to sie stanie duzo razy pod rzad
                i = 0;
              }
              prosto(30);
              BTserial.print("^");
              BTserial.print(i);
            }
            
            else if ((pomiar_lewy == 0) && (pomiar_lewy_max == 0) && ( pomiar_srodek == 1) && (pomiar_prawy == 1) &&(pomiar_prawy_max == 0)){
              w_prawo(30);
              i =0;
              BTserial.print("P");
            }

             else if ((pomiar_lewy == 0) && (pomiar_lewy_max == 0) && (pomiar_srodek == 0 ) && (pomiar_prawy == 1) &&(pomiar_prawy_max == 0)){
              w_prawo(30);
              i =0;
              BTserial.print("P");
            }

            else if ((pomiar_lewy == 1) && (pomiar_lewy_max == 0) && ( pomiar_srodek == 1) && (pomiar_prawy == 0) &&(pomiar_prawy_max == 0)){
              w_lewo(30);
              i =0;
              BTserial.print("L");
            }
            
            else if ((pomiar_lewy == 1) && (pomiar_lewy_max == 0) && (pomiar_srodek == 0 ) && (pomiar_prawy == 0) &&(pomiar_prawy_max == 0)){
              w_lewo(30);
              i =0;
              BTserial.print("L");
            }

            else {
              BTserial.println(" ");
              BTserial.println("decyduje bo ");
              pomiar_print();
              BTserial.println("xxxxxxxxxxxxxxxxxxxxxxxxxx");
              delay(400);
              decyduj();
              delay(400);
              i =0;
            }

      break;
          
      case 1:
            manewr_lewo();
            mode = 0;
            delay(400);
      break;

      case 2:
            manewr_lewo();
            mode = 0;
            delay(400);
      break;

      case 3:
            manewr_prawo();
            mode = 0;
            delay(400);
      break;

      case 4:
            manewr_lewo();
            mode = 0;
            delay(400);
      break;

      case 5:
            //jedz dalej
            mode = 0;
      break;

      case 6:
            manewr_lewo();
            mode = 0;
            delay(400);
      break;

      case 7:
            manewr_zawroc();
            mode = 0;
            delay(400);
      break;

      case 8:
            BTserial.print("HURA DOJECHALEM DO KOŃCA!");
            mode = 0;
            return 0;
      break;
     
    }
    //BTserial.print(mode);
    
    serialEvent();                // tutaj jak wysle jakies polecenie na konsoli BT to mi wyjdzie z tej nieskonczonej petli do while
    if (stringComplete) {
      break;
    }

    }while(1);
     
  }
