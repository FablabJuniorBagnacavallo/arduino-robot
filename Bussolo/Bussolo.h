#ifndef Bussolo_h
#define Bussolo_h

#include <ArduinoRobot.h>

class Bussolo {
	public:
		Bussolo();
		void ruota(int rotazione, int velocita);
		void avanza(int velocita);

		int	velocita();
		int velocitaAngolare();
		int velocitaSx();
		int velocitaDx();
		
	private:
		int	direzione;
		int	velocita_lineare;
		int	velocita_angolare;
		int	velocita_sx;
		int	velocita_dx;
		int delta_velocita (int delta);
};

#endif
