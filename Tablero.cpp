#include "SDL/include/SDL_render.h"
#include "Tablero.h"


cell_state Tablero::getFicha(const uint x, const uint y) const
{
	if (x >= TAMA�O_TABLERO || y >= TAMA�O_TABLERO) return cell_state::INVALID;
	else return tablero[x][y];
}

void Tablero::ponerFicha(const uint x, const uint y, const cell_state nuevoEstado)
{

}

Tablero::Tablero()
{
	for (size_t i = 0; i < TAMA�O_TABLERO; i++)
	{
		for (size_t j = 0; j < TAMA�O_TABLERO; j++)
		{
			tablero[i][j] = cell_state::EMPTY;
		}
	}
	turnoActual = turn::GAME_START;
}

Tablero::~Tablero()
{

}

uint Tablero::getPuntosJ1() const
{
	return puntosJ1;
}
uint Tablero::getPuntosJ2() const
{
	return puntosJ2;
}

void Tablero::a�adirPunto(const ushort jugador)
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