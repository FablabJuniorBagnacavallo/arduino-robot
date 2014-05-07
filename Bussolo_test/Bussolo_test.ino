
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>
#include "Bussolo.h"

Bussolo	bussolo;

void setup() {
	Robot.begin();
	Robot.beginTFT();
	Robot.setCursor(0, 0);
}

void premiUnTasto() {
	int	key;
	
//	bussolo.visualizza("posizione: " + String(Robot.compassRead()));
//	bussolo.visualizza("premi un tasto");
	key = BUTTON_NONE;
//	while (key != BUTTON_MIDDLE) {
	while (key == BUTTON_NONE) {
		bussolo.visualizza("posizione: " + String(Robot.compassRead()), true);
		bussolo.visualizza("premi un tasto");
		delay(100);
		key = Robot.keyboardRead();
	}
	delay(1000);
}

void loop() {
	premiUnTasto();
	bussolo.init(Robot.compassRead());

	for (int i=0; i<4; i++) {
		bussolo.avanza(150);
		bussolo.gira(90);
		premiUnTasto();
	}
}