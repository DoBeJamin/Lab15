/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab15/src/Lab15.ino"

#include "oled-wing-adafruit.h"
#include "Particle.h"


void setup();
void loop();
void format_display ();
#line 6 "c:/Users/benja/OneDrive/Desktop/visualStudioCode/summerIOT/Lab15/src/Lab15.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);


//WatchDog wd;

OledWingAdafruit display;

//retained bool watchdogExpiredFlag = false;


void setup() {
  display.setup();

  pinMode(D5, INPUT);


  Watchdog.init(WatchdogConfiguration().timeout(5s));
  Watchdog.start();
  //Watchdog.onExpired([]() { watchdogExpiredFlag = true; });
  format_display();
  if (System.resetReason() == RESET_REASON_WATCHDOG) {
    display.print("watchdog reset");
    //watchdogExpiredFlag = false;
  } else {
    display.print("normal reset");
  }
  display.display();
}

void loop() {
  display.loop();
  if (digitalRead(D5)) {
    Watchdog.refresh();
  }

}



void format_display () {
  //sets up basic formatting for when using the display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE); 
  display.setCursor(0,0);
}