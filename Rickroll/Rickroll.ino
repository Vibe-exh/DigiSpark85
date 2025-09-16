
#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("https://www.youtube.com/watch?v=hB7CDrVnNCs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_F11);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_F);
}
  
void loop() {  

}