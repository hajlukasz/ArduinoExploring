/*
  pomiary.cpp

*/

#include "Arduino.h"
#include "pomiary.h"

pomiary::pomiary()
{
int pomiar_lewy_max = 0;
int pomiar_lewy = 0;
int pomiar_srodek = 0;
int pomiar_prawy = 0;
int pomiar_prawy_max = 0;
int kalibracja_lewy_max =1023;
int kalibracja_lewy =1023;
int kalibracja_prawy =1023;
int kalibracja_prawy_max =1023;
int kalibracja_srodek =1023;

  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);  
  pinMode(A5, INPUT);  
  analogWrite(EnA,150);
  analogWrite(EnB,185);
}

void pomiary::pomiar()
{
    pomiar_lewy_max = analogRead(A4);
  pomiar_lewy = analogRead(A3);
  pomiar_srodek = analogRead(A2);
  pomiar_prawy = analogRead(A1);
  pomiar_prawy_max = analogRead(A0);  

   if (pomiar_lewy_max > kalibracja_lewy_max){
    pomiar_lewy_max = 1;
  }
  else {
    pomiar_lewy_max = 0;
  }

  
  if (pomiar_lewy > kalibracja_lewy){
    pomiar_lewy = 1;
  }
   else {
    pomiar_lewy = 0;
  }

  
  if (pomiar_srodek > kalibracja_srodek){
    pomiar_srodek = 1;
  }
   else {
    pomiar_srodek = 0;
  }


  if (pomiar_prawy > kalibracja_prawy){
    pomiar_prawy = 1;
  }
   else {
    pomiar_prawy = 0;
  }
  
  if (pomiar_prawy_max > kalibracja_prawy_max){
    pomiar_prawy_max = 1;
  }
   else {
    pomiar_prawy_max = 0;
  }
 
}

void pomiary::kalibracja()
{
  int roznica = 150;                //zmien jesli chcesz zeby ³apa³ jedynke przy wiekszej zmianie
  int pomiary_kalibracja[9][4];   //tablica na potrzebne pomiary

  while(kalibracja_lewy_max > 800 || kalibracja_lewy > 800 || kalibracja_srodek > 800 || kalibracja_prawy > 800 || kalibracja_prawy_max > 800){              //petla z takimi warunnkami zeby mi nie wyszla g³upota [case np jak stoi jednym czujnikiem przypadkiem na lini zamiast na pod³ozu]
  
    for (int i =0;i<10; i++){
      pomiar();
      pomiary_kalibracja[i][0] = pomiar_lewy_max;
      pomiary_kalibracja[i][1] = pomiar_lewy;
      pomiary_kalibracja[i][2] = pomiar_srodek;
      pomiary_kalibracja[i][3] = pomiar_prawy;
      pomiary_kalibracja[i][4] = pomiar_prawy_max;
      delay(50);   
    };

    int suma[4],srednia[4];

    for (int i = 0; i<10; i++){
       suma[0] = pomiary_kalibracja[i][0];
       suma[1] = pomiary_kalibracja[i][1];
       suma[2] = pomiary_kalibracja[i][2];
       suma[3] = pomiary_kalibracja[i][3];
       suma[4] = pomiary_kalibracja[i][4];
     }

    kalibracja_lewy_max = suma[0] / 10;
    kalibracja_lewy = suma[1] /10;
    kalibracja_srodek = suma[2] /10;
    kalibracja_prawy = suma[3] /10;
    kalibracja_prawy_max = suma[4] /10;
  }
}