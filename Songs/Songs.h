





#ifndef Songs_h
#define Songs_h

#include "Arduino.h"

class SuperMario
{
public:
  SongPin(int pin);
  void sing(int s);
  void buzz(int targetPin, long frequency, long length);
  void mario();
private:
  int _pin;
};

class Zelda{
public:
  SongPin(int pin);
  void zelda(int targetPin);
private:
  int _pin;
}

#endif
