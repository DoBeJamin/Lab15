
#include "oled-wing-adafruit.h"
#include "Particle.h"


SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup() {

  display.setup();

  pinMode(D5, INPUT);


  Watchdog.init(WatchdogConfiguration().timeout(5s));
  Watchdog.start();

  format_display();
  if (System.resetReason() == RESET_REASON_WATCHDOG) {
    //checks if last reset was due to a watchdog
    display.print("watchdog reset");
  } else {
    display.print("normal reset");
  }
  display.display();
}

void loop() {
  display.loop();
  if (digitalRead(D5)) {
    //refresh if D5 is high
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