void loop() {
 
  if (stringComplete) {
    
    Serial.println(inputString.toInt());
    int spr = inputString.toInt();
    int czas = 0;
    if (spr < 1000){
      czas  = spr;
      Serial.println("prosto");
      Serial.println(czas);
      prosto(czas);
      
    }
    else if (spr >= 1000 && spr <2000){
      czas = spr - 1000;
      Serial.println("prawo");
      Serial.println(czas);
      w_prawo(czas);
      
    }
    else if (spr >= 2000 && spr <3000){
      czas = spr - 2000;
      Serial.println("lewo");
      Serial.println(czas);
      w_lewo(czas);
      
    }
    else if (spr >= 3000 && spr <4000){
        czas = spr - 3000;
      Serial.println("cofaj233");
      Serial.println(czas);
      cofaj(czas);
      
    }

     else if (spr >= 4000 && spr <10000){
        czas = spr - 4000;
      Serial.println("following");
      Serial.println(czas);
      po_lini(czas);
      
    }

      else if (spr >= 10000){
      delay(1000);
      decyduj();
      delay(1000);
      manewr_lewo();
    }

    // clear the string:
    inputString = "";
    stringComplete = false;
}
  
  delay(1000);
  pomiar_print();
  pomiar();
  Serial.print("LEWY > >   ");
  Serial.print(pomiar_lewy_max);
  Serial.print("  || ");
  Serial.print(pomiar_lewy);
  Serial.print("  || ");
  Serial.print(pomiar_srodek);
  Serial.print("  || ");
  Serial.print(pomiar_prawy);
  Serial.print("  || ");
  Serial.print(pomiar_prawy_max);
  Serial.println("  < < PRAWY");
  Serial.println("_____________________________________________________________");
}





void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
