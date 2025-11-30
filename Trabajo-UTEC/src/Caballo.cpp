#include "../include/Caballo.h"
#include "../include/Tablero.h"

/*

Ficha: Caballo
- Movimiento: Se mueve en forma de "L", es decir, dos casillas en una dirección y luego una casilla perpendicular.
- Captura: Puede capturar cualquier pieza enemiga que se encuentre en la casilla de destino.
- Restricciones: No puede moverse a una casilla ocupada por una pieza del mismo color.

*/

Caballo::Caballo(const Color& color, const Posicion& pos)
    : Pieza(color, TipoPieza::CABALLO, pos) {}

bool Caballo::movimientovalido(const Posicion& destino, const Tablero& tablero) const {
    int filaDiff = abs(destino.fila - this->pos.fila);
    int colDiff = abs(destino.columna - this->pos.columna);

    if (!((filaDiff == 2 && colDiff == 1) || (filaDiff == 1 && colDiff == 2))) {
        return false; // No es un movimiento en "L"
    }

    Pieza* piezaEnDestino = tablero.getPieza(destino);

    // El movimiento es válido si el destino está vacío O si contiene una pieza enemiga.
    // De lo contrario (si contiene una pieza aliada), es inválido.
    return piezaEnDestino == nullptr || piezaEnDestino->getColor() != this->color;
}

string Caballo::getSimbolo() const {
	if (this->color == Color::BLANCO) {
		return "CB";
	} else {
		return "CN";
	}
}