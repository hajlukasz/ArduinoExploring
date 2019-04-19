/*
  pomiary.h
*/

#ifndef pomiary_h
#define pomiary_h

#include "Arduino.h"


#define EnA 10
#define EnB 5
#define In2 8
#define In1 9
#define In4 6
#define In3 7


class pomiary
{
  public:
    pomiary();
    void pomiar();
    void kalibracja();
};

#endif