
//Definicja wyprowadzeń pierwszej diody
#define czerwona 3
#define zielona 5
#define niebieska 6
 
//Definicja wyprowadzeń drugiej diody
#define czerwona2 9
#define zielona2 10
#define niebieska2 11
 
void setup() {
  pinMode(czerwona, OUTPUT); //Konfiguracja wyprowadzeń jako wyjścia
  pinMode(zielona, OUTPUT);
  pinMode(niebieska, OUTPUT);
  pinMode(czerwona2, OUTPUT);
  pinMode(zielona2, OUTPUT);
  pinMode(niebieska2, OUTPUT);
}
 
void loop() {
  int zmiana = 0;
 
  for (zmiana = 0; zmiana < 255; zmiana++) { //Płynna zmiana kolorów
    analogWrite(czerwona, 0);  
    analogWrite(zielona, zmiana);
    analogWrite(niebieska, 255 - zmiana);   
 
    analogWrite(czerwona2, zmiana);  
    analogWrite(zielona2, 255 - zmiana);
    analogWrite(niebieska2, 0);
 
    delay(10); //Krótkie opóźnienie, aby efekt był widoczny dla ludzkiego oka
  } 
}
