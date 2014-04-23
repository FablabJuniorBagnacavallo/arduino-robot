
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>
#include "Bussolo.h"

Bussolo	bussolo;

void setup() {
	int	key;
	int	direzione_iniziale;
	
	Robot.begin();
	Robot.beginTFT();
	Robot.setCursor(0, 0);

	key = BUTTON_NONE;
	while (key != BUTTON_MIDDLE) {
		delay(100);
		key = Robot.keyboardRead();
	}

	direzione_iniziale = Robot.compassRead();
	Robot.print(String(direzione_iniziale));
	bussolo.init(direzione_iniziale);
	delay(500);
}

void loop() {
	int	key;

	key = Robot.keyboardRead();
	if (key == BUTTON_LEFT) {
		bussolo.ruota(-90, 100);
	} else if (key == BUTTON_RIGHT) {
		bussolo.ruota( 90, 100);
	}

	bussolo.avanza(100);
	delay(100);
}