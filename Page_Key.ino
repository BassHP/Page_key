//Simple and fun page up and down scroller keyboard.

//http://www.basshp.msxall.com

#include "DigiKeyboard.h"

const int tempo= 10; // tempo entre as ações
const int key_0 = 0;
const int key_1 = 1;

int count0 = 0; 
int count1 = 0;


void setup() 
{
 pinMode (key_0, INPUT);
 pinMode (key_1, INPUT);
}


void loop() 
{
  DigiKeyboard.sendKeyStroke(0);
  
  if (digitalRead(key_0) == HIGH && count0 == 0) // Aciona o page down (0x4B)
  {
    count0 = 1;
    DigiKeyboard.sendKeyPress(0x4E); 
    DigiKeyboard.delay(tempo);
  }
  else if (digitalRead(key_0) == LOW && count0 == 1) // Condição que evita a repetição da tecla
  {
    count0 = 0;
  }
  if (digitalRead(key_1) == HIGH && count1 == 0) // Aciona o page up (0x4B)
  {
    count1 = 1;
    DigiKeyboard.sendKeyPress(0x4B); 
    DigiKeyboard.delay(tempo);
  }
  else if (digitalRead(key_1) == LOW && count1 == 1) // Condição que evita a repetição da tecla
  {
    count1 = 0;
  }
 
}
