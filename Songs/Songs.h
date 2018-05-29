





#ifndef Songs_h
#define Songs_h

#include "Arduino.h"

public:
  SongPin(int pin);
private:
  int _pin;

class SuperMario
{

  void sing(int s);
  void buzz(int targetPin, long frequency, long length);
  void mario();

};

class Zelda
{
public:
  void zelda(int targetPin);
};

#endif
