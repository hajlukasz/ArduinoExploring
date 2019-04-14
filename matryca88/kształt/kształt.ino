#define x1 2
#define x2 3
#define x3 4
#define x4 5
#define x5 6
#define x6 7
#define x7 8
#define x8 9
#define y1 10
#define y2 11
#define y3 12
#define y4 13
#define y5 19
#define y6 18
#define y7 17
#define y8 16

int xlabel[] = {x1,x2,x3,x4,x5,x6,x7,x8};
int sizex = 8;

int ylabel[] = {y1,y2,y3,y4,y5,y6,y7,y8};
int sizey = 8;

void skanujy()
{
  
  for(int i=0; i<sizey; i++)
      {
          digitalWrite(ylabel[i], HIGH);
          delay(100); 
          digitalWrite(ylabel[i], LOW);   
 
      }
      
}

void setup() {

for(int i=0; i<sizex; i++)
  {
    pinMode(xlabel[i], OUTPUT); 
     digitalWrite(xlabel[i], HIGH);
  }

   for(int i=0; i<sizey; i++)
  {
    pinMode(ylabel[i], OUTPUT); 
    digitalWrite(ylabel[i], LOW);
  }

}

void loop() {
  
       digitalWrite(ylabel[0], HIGH);
       digitalWrite(x1, LOW);digitalWrite(x2, LOW);digitalWrite(x3, LOW);digitalWrite(x4, LOW);digitalWrite(x5, LOW);digitalWrite(x6, LOW);digitalWrite(x7, LOW);digitalWrite(x8, LOW);
       delay(1); 
       digitalWrite(ylabel[0], LOW);
       
       digitalWrite(ylabel[1], HIGH);
       digitalWrite(x1, LOW);digitalWrite(x2, HIGH);digitalWrite(x3, HIGH);digitalWrite(x4, HIGH);digitalWrite(x5, HIGH);digitalWrite(x6,HIGH);digitalWrite(x7, HIGH);digitalWrite(x8, LOW);
       delay(1); 
       digitalWrite(ylabel[1], LOW);

       digitalWrite(ylabel[2], HIGH);
       digitalWrite(x1, LOW);digitalWrite(x2, LOW);digitalWrite(x3, LOW);digitalWrite(x4, HIGH);digitalWrite(x5, HIGH);digitalWrite(x6, LOW);digitalWrite(x7, LOW);digitalWrite(x8, LOW);
       delay(1); 
       digitalWrite(ylabel[2], LOW);

       digitalWrite(ylabel[3], HIGH);
       digitalWrite(x1, HIGH);digitalWrite(x2, HIGH);digitalWrite(x3, LOW);digitalWrite(x4, HIGH);digitalWrite(x5, HIGH);digitalWrite(x6, LOW);digitalWrite(x7, HIGH);digitalWrite(x8, HIGH);
       delay(1); 
       digitalWrite(ylabel[3], LOW);

       digitalWrite(ylabel[4], HIGH);
       digitalWrite(x1, HIGH);digitalWrite(x2, HIGH);digitalWrite(x3, LOW);digitalWrite(x4, HIGH);digitalWrite(x5, HIGH);digitalWrite(x6, LOW);digitalWrite(x7, HIGH);digitalWrite(x8, HIGH);
       delay(1); 
       digitalWrite(ylabel[4], LOW);

       digitalWrite(ylabel[5], HIGH);
       digitalWrite(x1, HIGH);digitalWrite(x2, HIGH);digitalWrite(x3, LOW);digitalWrite(x4, HIGH);digitalWrite(x5, HIGH);digitalWrite(x6, LOW);digitalWrite(x7, HIGH);digitalWrite(x8, HIGH);
       delay(1); 
       digitalWrite(ylabel[5], LOW);

       digitalWrite(ylabel[6], HIGH);
       digitalWrite(x1, HIGH);digitalWrite(x2, HIGH);digitalWrite(x3, LOW);digitalWrite(x4, HIGH);digitalWrite(x5, HIGH);digitalWrite(x6, LOW);digitalWrite(x7, HIGH);digitalWrite(x8, HIGH);
       delay(1); 
       digitalWrite(ylabel[6], LOW);

       digitalWrite(ylabel[7], HIGH);
       digitalWrite(x1, HIGH);digitalWrite(x2, HIGH);digitalWrite(x3, LOW);digitalWrite(x4, LOW);digitalWrite(x5, LOW);digitalWrite(x6, LOW);digitalWrite(x7, HIGH);digitalWrite(x8, HIGH);
       delay(1); 
       digitalWrite(ylabel[7], LOW);
       
      
}
