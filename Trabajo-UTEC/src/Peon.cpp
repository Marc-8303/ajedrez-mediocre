#include "../include/Peon.h"
#include "../include/Tablero.h"

/*

FICHA: PEON
- Movimiento: Avanza una casilla hacia adelante.
- Captura: si esta en sus diagonales de una casilla, captura la pieza enemiga.
- Restricciones: No puede moverse si la casilla de destino está ocupada.

*/

Peon::Peon(const Color& color, const Posicion& pos)
    : Pieza(color, TipoPieza::PEON, pos) {}

bool Peon::movimientovalido(const Posicion& destino, const Tablero& tablero) const {
    int direccion = (this->color == Color::BLANCO) ? 1 : -1;

    if (destino.columna == this->pos.columna) {
        if (destino.fila == this->pos.fila + direccion) {
            return tablero.getPieza(destino) == nullptr;
        }

        if (!this->yaSeMovio() && destino.fila == this->pos.fila + 2 * direccion) {
            Posicion casillaIntermedia = {this->pos.fila + direccion, this->pos.columna};
            return tablero.getPieza(casillaIntermedia) == nullptr && tablero.getPieza(destino) == nullptr;
        }
    } else if (abs(destino.columna - this->pos.columna) == 1 && destino.fila == this->pos.fila + direccion) {
        Pieza* piezaEnDestino = tablero.getPieza(destino);
        return piezaEnDestino != nullptr && piezaEnDestino->getColor() != this->color;
    }

    return false;
}

string Peon::getSimbolo() const {
	if (this->color == Color::BLANCO) {
		return "PB";
	} else {
		return "PN";
	}
}
