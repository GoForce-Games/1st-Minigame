#pragma once


#include "Macros.h"




#define TAMAÑO_TABLERO 8

enum class cell_state {
	EMPTY,
	PLAYER1,
	PLAYER2,
	INVALID = -1
};

enum class turn {
	GAME_START,
	PLAYER_1,
	PLAYER_2,
	GAME_END
};

class Tablero
{
private:
	uint puntosJ1 = 0, puntosJ2 = 0;
	turn turnoActual;
	cell_state tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO];

public:
	Tablero();
	~Tablero();

	cell_state getFicha(const uint x, const uint y) const;

	// Comprueba cual es la primera fila en la que hay una ficha e intenta colocar la nueva en la anterior
	// Hay que poner un if que compruebe el turno actual
	void ponerFicha(const uint x, const uint y, const cell_state nuevoEstado);

	uint getPuntosJ1() const;
	uint getPuntosJ2() const;

	// Añade un punto al jugador especificado
	void añadirPunto(const ushort jugador);

	void dibujaTablero(const SDL_Renderer* renderer);

	ushort compruebaGanador();



};

