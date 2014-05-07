#include <ArduinoRobot.h>
#include "Bussolo.h"

Bussolo::Bussolo() {}

//---------------------------------------------------------

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
	float	result;
	
	if (delta == 0) {
		result = 0;
	} else {
		float delta_rad = ((float)delta)/180;
		
		if (delta > 0) {
			result = delta_rad + 0.5;
		} else {
			result = delta_rad - 0.5;
		}
	}

	return result * velocita_angolare;
}

//---------------------------------------------------------

void Bussolo::init(int direzione_iniziale) {
	direzione = direzione_iniziale;
	velocita_lineare = 0;
	velocita_sx = 0;
	velocita_dx = 0;
	velocita_angolare = 100;
}

void Bussolo::ruota(int rotazione, int velocita) {
	if (abs(rotazione) <= 180) {
		direzione = (direzione + rotazione + 360) % 360;
		velocita_angolare = velocita;
	} else {
		visualizza("ERRORE!! rotazione non compatibile: " + String(rotazione));
	}
}

void Bussolo::visualizza(String value, bool pulisci) {
	if (pulisci) {
		Robot.clearScreen();
		Robot.setCursor(0, 0);
	}
	Robot.println(value);
}

void Bussolo::procedi(int velocita) {
	int d;
	int t;
	int dv;

	velocita_lineare = velocita;
	dv = delta_velocita(normalizza_direzione((360 + direzione - Robot.compassRead()) % 360));
	visualizza("dv: " + String(dv));
	
	velocita_sx = velocita_lineare + dv;
	velocita_dx = velocita_lineare - dv;

	visualizza("[" + String(velocita_sx) + ", " + String(velocita_dx) + "]");
	Robot.motorsWrite(velocita_dx, velocita_sx);
}

void Bussolo::gira(int rotazione) {
	int	posizioneCorrente;
	
	ruota(rotazione, 100);

	posizioneCorrente = Robot.compassRead();
	while (abs(normalizza_direzione(posizioneCorrente - direzione)) > 0) {
		visualizza("--- gira [" + String(posizioneCorrente) + " - " + direzione + "] == " + String(normalizza_direzione(posizioneCorrente - direzione)), true);
		procedi(0);
		delay(10);
		posizioneCorrente = Robot.compassRead();
	}

	stop();
	visualizza("<<< gira [" + String(Robot.compassRead()) + " - " + direzione + "]", true);
}

void Bussolo::avanza(int distanza) {
	int	target = distanza * 20;
	unsigned long time = millis();
	
	while (millis() - time < target) {
		procedi(100);
		delay(10);
	}

	stop();
}

void Bussolo::stop() {
	velocita_lineare = 0;
	Robot.motorsStop();
//	Robot.motorsWrite(0, 0);
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

int Bussolo::target() {
	return direzione;
}

