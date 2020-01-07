



void loop() {
 
  if (stringComplete) {
    
    BTserial.println(inputString.toInt());
    int spr = inputString.toInt();
    int czas = 0;
    if (spr < 1000){
      czas  = spr;
      BTserial.println("prosto");
      BTserial.println(czas);
      prosto(czas);
      
    }
    else if (spr >= 1000 && spr <2000){
      czas = spr - 1000;
      BTserial.println("prawo");
      BTserial.println(czas);
      w_prawo(czas);
      
    }
    else if (spr >= 2000 && spr <3000){
      czas = spr - 2000;
      BTserial.println("lewo");
      BTserial.println(czas);
      w_lewo(czas);
      
    }
    else if (spr >= 3000 && spr <4000){
        czas = spr - 3000;
      BTserial.println("cofaj233");
      BTserial.println(czas);
      cofaj(czas);
      
    }

     else if (spr >= 4000 && spr <20000){
        czas = spr - 4000;
      BTserial.println("following");
      BTserial.println(czas);
      po_lini(czas);
      
    }


    // clear the string:
    inputString = "";
    stringComplete = false;
}


  
  delay(1000);
  pomiar_print();
  pomiar();
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

  serialEvent();
}





void serialEvent() {
  while (BTserial.available()) {
    // get the new byte:
    char inChar = (char)BTserial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
