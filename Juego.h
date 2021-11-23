#ifndef _JUEGO_H
#define _JUEGO_H

#include <iostream>
#include <string>

#include "Tablero.h"
#include "Jugador.h"
#include "Carta.h"
#include "Cola.h"
#include "Interfaz.h"

class Juego {

private:

	Lista < Jugador * > * jugadores; // lista circular de jugadores
    Cola < Carta * > * mazo;
    Jugador * jugadorEnTurno; // sirve para luego saber quien fue el ultimo que jugo, quien gano
    Tablero * tablero;
    Interfaz * interfaz;
    unsigned int cantidadMaximaCartas;  // Cantidad maxima de cartas que puede tener un jugador en la mano
  	int jugadaAnterior[2][3];   // Representa las coordenadas de donde se hizo la ultima modificacion en el tablero

public:
	/*
	 * Pre:	recibe las 3 dimensiones que tendra el tablero,
	 * la cantidad de fichas seguidas necesarias para ganar, cantidad de jugadores
	 * distinta de 0, y la cantidad de cartas en mano que se puede tener
	 *
	 * Post: valida y crea un nuevo juego. El juego se crea con un tablero de ancho x alto x profundo
	 * dimensiones, cantidadFichas que indica las necesarias para ganar, cantidadJugadores
	 * y cantidadCartas en mano que se puede tener
	 */
	Juego();

	/*
	 * Post: se libera memoria del heap usada para tablero, lista de jugadores, mazo de cartas
	 */
	~Juego();

	/*
	 * recibe coordenadas en el tablero; el jugador es el actual
	 */
	void ponerFicha(unsigned int x, unsigned int y, unsigned int z);
	// con try - except

	/*
	 * juega jaja
	 */
    void jugar();

	/*
	 * recibe 2 coordenadas en el tablero; el jugador es el actual
	 */
	void moverFicha(unsigned int x1, unsigned int y1, unsigned int z1,
                    unsigned int x2, unsigned int y2, unsigned int z2);
	// con try - except


	/*
	 * Pre: recibe el número perteneciente a una carta del mazo (del 1 al 6?)
	 * Post: si el jugador no posee esa carta, no se hace nada
	 * el juego actúa según lo que haga la carta
	 */
	void activarCarta( unsigned int );


	/* avanza una posicion en la lista de jugadores
	 * establece el nuevo jugadorEnTurno
	 */
 	void cambiarTurno();


	/* itera la lista de jugadores, para cada uno
	 * 		retira una carta del mazo
	 *    agrega una carta al jugador (llama a tomarCarta)
	 * post: disminuyen cartas del mazo, cada jugador toma una carta
	 */
	//void repartirCartas();

	void entregarCarta();

private:

    std::string pedirNombre( int );
    bool validarCantidadJugadores(int);
    bool validarCantidadCartas(int);
    bool validarDimensiones(int, int, int);

    bool validarPosicionEnElTablero( int, int, int );

    void bloquearSiguienteJugador();

    void bloquearFicha( int, int, int );

    void bloquearCasillero( int, int, int );

    void volverJugadaAtras();

    void devolverFichaAJugadorAnterior();

};

#endif // _JUEGO_H
