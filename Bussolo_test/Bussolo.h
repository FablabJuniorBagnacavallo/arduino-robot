#ifndef Bussolo_h
#define Bussolo_h

#include <ArduinoRobot.h>

class Bussolo {
	public:
		Bussolo();
		void init(int direzione_iniziale);
		void ruota(int rotazione, int velocita);
		void procedi(int velocita);
		void stop();
		
		void gira(int rotazione);
		void avanza(int distanza);

		int	velocita();
		int velocitaAngolare();
		int velocitaSx();
		int velocitaDx();
		int target();
		
		void visualizza(String value, bool pulisci=false);

	private:
		int	direzione;
		int	velocita_lineare;
		int	velocita_angolare;
		int	velocita_sx;
		int	velocita_dx;
		int delta_velocita (int delta);
};

#endif