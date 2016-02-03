#include <OnewireKeypad.h>

char KEYS[]= {
  '1','2','3',//'A',
  '4','5','6',//'B',
  '7','8','9',//'C',
  '0','0','0',//'D'
};

OnewireKeypad <Print, 12 > Keypad(Serial, KEYS, 4, 3, A5, 4700, 1000 );

void setup ()
{
  Serial.begin(115200);
}
 
void loop() 
{
  Keypad.SetHoldTime(100);  // Key held time in ms
  Keypad.SetDebounceTime(70); // Key Debounce time in ms
  
  if ((Keypad.Key_State() == 3)) {  // not pressed = 0, pressed = 1, released = 2,  held = 3
  
    char keypress = Keypad.Getkey();  // put value of key pressed in variable 'keypress'
    Serial.println("Keypad Key: ");
    Serial.println(keypress);  // Display value on Serial Monitor
    while ((Keypad.Key_State())){}  // Stay here while Key is held down
  }
}
  

