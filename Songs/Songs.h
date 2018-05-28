





#ifndef Songs_h
#define Songs_h

#include "Arduino.h"

class SuperMario
{
public:
  SongPin(int pin);
  void sing(int s);
  void buzz(int targetPin, long frequency, long length);
  void notes();
private:
  int _pin;
};

#endif
