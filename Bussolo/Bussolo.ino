#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>
#include "Bussolo.h"

Bussolo	bussolo;

void setup() {
	int	key;

	Robot.begin();
	Robot.beginTFT();
	Robot.setCursor(0, 0);

	key = BUTTON_NONE;
	while (key != BUTTON_MIDDLE) {
		delay(100);
		key = Robot.keyboardRead();
	}

	bussolo = Bussolo();
}

void loop() {
	bussolo.avanza(100);
	Robot.clearScreen();
	Robot.setCursor(0, 0);
	Robot.print("[" + String(bussolo.velocita()) + " - " + String(bussolo.velocitaAngolare()) + " [ " + String(bussolo.velocitaSx()) + " - " + String(bussolo.velocitaDx()) + "]");
}