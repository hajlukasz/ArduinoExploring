#define EnA 5   //prawy
#define EnB 10  // lewy
#define In1 6   // prawy ?tyl
#define In2 7   // prawy przod
#define In3 8   //lewy tył
#define In4 9   //lewy przod

#include <SoftwareSerial.h>
SoftwareSerial BTserial(2,3 ); // RX | TX

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
int mode = 0;

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
