#include "../include/Torre.h"
#include "../include/Tablero.h"


/*

Ficha: TORRE
- Movimiento lineal: Se mueve cualquier número de casillas en línea recta - horizontal o verticalmente.
- Captura: La torre captura una pieza enemiga moviéndose a la casilla ocup

*/

Torre::Torre(const Color& color, const Posicion& pos)
    : Pieza(color, TipoPieza::TORRE, pos) {}

bool Torre::movimientovalido(const Posicion& destino, const Tablero& tablero) const {
    int filaDiff = destino.fila - this->pos.fila;
    int colDiff = destino.columna - this->pos.columna;

    // Verifica si el movimiento es horizontal o vertical
    if (filaDiff == 0 || colDiff == 0) {
        int stepFila = (filaDiff == 0) ? 0 : (filaDiff / abs(filaDiff));
        int stepCol = (colDiff == 0) ? 0 : (colDiff / abs(colDiff));

        int currentFila = this->pos.fila + stepFila;
        int currentCol = this->pos.columna + stepCol;

        // Verifica si hay piezas en el camino
        while (currentFila != destino.fila || currentCol != destino.columna) {
            Posicion casillaIntermedia = {currentFila, currentCol};
            if (tablero.getPieza(casillaIntermedia) != nullptr) {
                return false;
            }
            currentFila += stepFila;
            currentCol += stepCol;
        }

        // Verifica si la casilla de destino está ocupada por una pieza del mismo color
        Pieza* piezaEnDestino = tablero.getPieza(destino);
        return piezaEnDestino == nullptr || piezaEnDestino->getColor() != this->color;
    }

    return false;
}

string Torre::getSimbolo() const {
    if (this->color == Color::BLANCO) {
        return "TB";
    } else {
        return "TN";
    }
}