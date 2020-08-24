#include "functionPrototype.h"
void alarm_check(){
  if(Mole_celsius >= (float)setMole_Temp&&
  (Mole_celsius <= (float)setMole_Temp+1.0f||Mole_celsius <= (float)setMole_Temp-1.0f))
    curent_alarm = HIGH;
  else
    curent_alarm = LOW;
}
