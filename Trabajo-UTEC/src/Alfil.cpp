#include "../include/Alfil.h"
#include "../include/Tablero.h"
#include <cmath>

using namespace std;

Alfil::Alfil(const Color& color, const Posicion& pos)
    : Pieza(color, TipoPieza::ALFIL, pos) {}

bool Alfil::movimientovalido(const Posicion& destino, const Tablero& tablero) const {
    if (destino.fila == this->pos.fila && destino.columna == this->pos.columna)
        return false;

    int df = destino.fila - this->pos.fila;
    int dc = destino.columna - this->pos.columna;

    if (abs(df) != abs(dc))
        return false;

    int stepF = (df > 0) ? 1 : -1;
    int stepC = (dc > 0) ? 1 : -1;

    int f = this->pos.fila + stepF;
    int c = this->pos.columna + stepC;
    while (f != destino.fila && c != destino.columna) {
        Posicion p{f, c};
        if (tablero.getPieza(p) != nullptr)
            return false;
        f += stepF;
        c += stepC;
    }

    Pieza* destinoP = tablero.getPieza(destino);
    if (destinoP == nullptr)
        return true;

    return destinoP->getColor() != this->color;
}

string Alfil::getSimbolo() const {
	if (this->color == Color::BLANCO) {
		return "AB";
	} else {
		return "AN";
	}
}
