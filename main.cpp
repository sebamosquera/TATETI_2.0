#include "Juego.h"


int main () {


	try {
		Juego * j = new Juego();

		j->jugar();

		delete j;
	}
	catch (...) {
	}


    return 0;
}
