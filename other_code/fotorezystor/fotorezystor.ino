int diody[] = {3,11,13};    // tablica zawierająca numery wyj. cyfrowych
int size = 3;       // wielkość tablicy
int j = 0;        // tworzymy zmienną „j” i przypisujemy jej wartość 0

void setup()        // część przygotowawcza

{
  Serial.begin(9600);
    for (int i=0; i< size; i++)   // pętla for
 {
    pinMode(diody[i], OUTPUT);    //ustawienie pinów jako wyjścia 
  }
}

void loop()       // główna pętla programu

{
j = analogRead(0);  //przypisanie do zmiennej „j” wartości odczytanej z wejścia analogowego 0
Serial.print(j);
Serial.println(" ");
                      //dzielimy otrzymaną wartość przez 128

    if (j>600 && j<785)       //wejście w przypadku poprawności wyrażenia j większe równe i
      {
      digitalWrite(diody[0], HIGH);
      digitalWrite(diody[1], LOW);
      digitalWrite(diody[2], LOW);
      // ustaw stan wysoki na diodach
     } 
    else if ( j>=785 && j<850)         //wykonanie kodu w przypadku niespełnienia warunku
    {
      digitalWrite(diody[0], HIGH);
      digitalWrite(diody[1], HIGH);
      digitalWrite(diody[2], LOW);  //ustaw stan niski na diodach
    }

    else if (j>850)
    {
      digitalWrite(diody[0], HIGH);
      digitalWrite(diody[1], HIGH);
      digitalWrite(diody[2], HIGH);
    }

    else 
    {
      digitalWrite(diody[0], LOW);
      digitalWrite(diody[1], LOW);
      digitalWrite(diody[2], LOW);
    }
  
  delay(200);       //czekaj 200 milisekund
}
