
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
	Robot.print(String(Robot.compassRead()));

	key = BUTTON_NONE;
	while (key != BUTTON_MIDDLE) {
		delay(100);
		key = Robot.keyboardRead();
	}

	bussolo.init(Robot.compassRead());
}

void loop() {
/*	
	Robot.clearScreen();
	Robot.setCursor(0, 0);

	Robot.print(String(Robot.compassRead()));
*/
	delay(500);
	/*
	bussolo.avanza(100);
	Robot.clearScreen();
	Robot.setCursor(0, 0);
	Robot.print("[" + String(bussolo.velocita()) + " - " + String(bussolo.velocitaAngolare()) + " [ " + String(bussolo.velocitaSx()) + " - " + String(bussolo.velocitaDx()) + "]");
	*/
}