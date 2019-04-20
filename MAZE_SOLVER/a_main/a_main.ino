#define EnA 10
#define EnB 4
#define In2 8
#define In1 9
#define In4 5
#define In3 6

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
