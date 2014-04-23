#include <ArduinoRobot.h>
#include "Bussolo.h"

Bussolo::Bussolo() {
//	direzione = Robot.compassRead();
	
}

void Bussolo::init(int direzione_iniziale) {
	direzione = direzione_iniziale;
	velocita_lineare = 0;
	velocita_sx = 0;
	velocita_dx = 0;
	velocita_angolare = 100;
}

void Bussolo::ruota(int rotazione, int velocita) {
	direzione = (direzione + rotazione) % 360;
	velocita_angolare = velocita;
}

int normalizza_direzione(int d) {
	int risultato;
	
	if (d > 180) {
		risultato = d - 360;
	} else {
		risultato = d;
	}
	
	return risultato;
}

int Bussolo::delta_velocita (int delta) {
	float delta_rad = ((float)delta)/180;
	return asin(delta_rad)*velocita_angolare;
}

void Bussolo::avanza(int velocita) {
	int d;
	int t;
	int dv;
	
	velocita_lineare = velocita;
	dv = delta_velocita(normalizza_direzione((360 + direzione - Robot.compassRead()) % 360));
	
	velocita_sx = velocita_lineare + dv;
	velocita_dx = velocita_lineare - dv;

	Robot.motorsWrite(velocita_dx, velocita_sx);
}

int	Bussolo::velocita() {
	return velocita_lineare;
}

int Bussolo::velocitaAngolare() {
	return velocita_angolare;
}

int Bussolo::velocitaSx() {
	return velocita_sx;
}

int Bussolo::velocitaDx() {
	return velocita_dx;
}