#include "SDL/include/SDL_render.h"
#include "Tablero.h"


cell_state Tablero::getFicha(const uint fila, const uint columna) const
{
	if (fila >= TAMAÑO_TABLERO || columna >= TAMAÑO_TABLERO) return cell_state::INVALID;
	else return tablero[fila][columna];
}

bool Tablero::ponerFicha(const uint columna, const cell_state nuevoEstado)
{
	if (tablero[0][columna] != cell_state::EMPTY) return false;

	int fila = -1;

	for (size_t i = 0; i < TAMAÑO_TABLERO; i++)
	{
		if (tablero[i][columna] == cell_state::EMPTY) fila = i;
	}
	
	// Como hay un return aqui no hace falta poner un else, ya que al codigo de mas abajo solo se llegara si NO se cumple el if
	if (fila == -1) return false; 

	tablero[fila][columna] = nuevoEstado;
	return true;
}

Tablero::Tablero()
{
	for (size_t i = 0; i < TAMAÑO_TABLERO; i++)
	{
		for (size_t j = 0; j < TAMAÑO_TABLERO; j++)
		{
			tablero[i][j] = cell_state::EMPTY;
		}
	}
	turnoActual = turn::GAME_START;
}

Tablero::~Tablero()
{
	// Para borrar matrices multidimensionales hay que hacerlo asi (un bucle por cada dimension mas alla de 1)
	for (size_t i = 0; i < TAMAÑO_TABLERO; i++)
	{
		delete[] tablero[i];
	}
	delete[] tablero;
}

uint Tablero::getPuntosJ1() const
{
	return puntosJ1;
}
uint Tablero::getPuntosJ2() const
{
	return puntosJ2;
}

void Tablero::añadirPunto(const ushort jugador)
{

}

void Tablero::dibujaTablero(const SDL_Renderer* renderer)
{

}

ushort Tablero::compruebaGanador()
{
	bool hayGanador = false;


	if (hayGanador) turnoActual = turn::GAME_END;
	return 0;
}