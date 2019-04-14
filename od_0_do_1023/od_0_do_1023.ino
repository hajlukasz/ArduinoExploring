#define A 11
#define B 7
#define C 4
#define D 2
#define E 13
#define F 10
#define G 5
#define c1 12
#define c2 9
#define c3 8
#define c4 6

int leds[] = {A,B,C,D,E,F,G};
int sizeleds = 7;

int common[] = {c1,c2,c3,c4};
int sizecommon = 4;

void zero()
{
   digitalWrite(A, LOW);
   digitalWrite(B, LOW);
   digitalWrite(C, LOW);
   digitalWrite(D, LOW);
   digitalWrite(E, LOW);
   digitalWrite(F, LOW);
   digitalWrite(G, HIGH);
}

void one()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void two()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void three()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void four()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void five()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void six()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void seven()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void eight()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void nine()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void digit(int number)
{
  switch (number)
  {
    case 4: 
      digitalWrite(c1,LOW);
      digitalWrite(c2,LOW);
      digitalWrite(c3,LOW);
      digitalWrite(c4,HIGH);
      break;
      
    case 3:
      digitalWrite(c1,LOW);
      digitalWrite(c2,LOW);
      digitalWrite(c3,HIGH);
      digitalWrite(c4,LOW);
      break;   
      
    case 2:
      digitalWrite(c1,LOW);
      digitalWrite(c2,HIGH);
      digitalWrite(c3,LOW);
      digitalWrite(c4,LOW);
      break;

     case 1:
      digitalWrite(c1,HIGH);
      digitalWrite(c2,LOW);
      digitalWrite(c3,LOW);
      digitalWrite(c4,LOW);
      break;
  }
}
void numbers(int number)
{
   switch (number)
   {
    case 0: 
      zero();
      break;
      
    case 1:
      one();
      break;
     
    case 2:
      two();
      break;
    
    case 3: // 3
      three();
      break;
    
    case 4:
      four();  
      break;
    
    case 5:
      five();
      break; 

    
    case 6:
      six();
      break;
    
    case 7:
      seven();
      break;
    
    case 8:
      eight();
      break;
    
    case 9:
      nine();
      break;
  
    default:
      zero();
    
}
}
void setup() {
  Serial.begin(9600);

  for(int i=0; i<sizeleds; i++)
  {
    pinMode(leds[i], OUTPUT); 
  }

   for(int i=0; i<sizecommon; i++)
  {
    pinMode(common[i], OUTPUT); 
    digitalWrite(common[i], LOW);
  }
  

}

void loop() {
  int value = analogRead(A0);
 
  Serial.println("liczba");
  Serial.println(value);
  
  
  if(value<10)
  {
    digit(4);
    numbers(value);
  }

  else if(value>=10 && value<100)
  {
    int tens = value/10;
    int ones = value-(tens*10);
    
    digit(4);
    numbers(ones);
    delay(10);
    
    digit(3);
    numbers(tens);
    delay(10);
  }

  else if(value>=100 && value<1000)
  {
    int hundreds = value/100;
    int tens = (value-(100*hundreds))/10;
    int ones = value-(100*hundreds)-(10*tens);

    digit(4);
    numbers(ones);
    delay(5);

    digit(3);
    numbers(tens);
    delay(5);

    digit(2);
    numbers(hundreds);
    delay(5);
  }

 else if(value>=1000)
 {
  int thousands = value/1000;
  int hundreds = (value-(thousands*1000))/100;
  int tens = (value-(1000*thousands)-(100*hundreds))/10;
  int ones = value-(100*hundreds)-(10*tens)-(1000*thousands);

    digit(4);
    numbers(ones);
    delay(5);

    digit(3);
    numbers(tens);
    delay(5);

    digit(2);
    numbers(hundreds);
    delay(5);

    digit(1);
    numbers(thousands);
    delay(5);
 }

 
}
