#include "../include/Reina.h"
#include "../include/Tablero.h"

/*

Ficha: REINA
- Movimiento: Se mueve cualquier número de casillas en línea recta - horizontal, vertical o
    diagonalmente.

- Captura: La reina captura una pieza enemiga moviéndose a la casilla ocupada por esa pieza.
- Restricciones: No puede saltar sobre otras piezas; todas las casillas entre la posición
    inicial y la posición final deben estar desocupadas.

*/

Reina::Reina(const Color& color, const Posicion& pos)
    : Pieza(color, TipoPieza::REINA, pos) {}

bool Reina::movimientovalido(const Posicion& destino, const Tablero& tablero) const {
    int filaDiff = destino.fila - this->pos.fila;
    int colDiff = destino.columna - this->pos.columna;

    if (filaDiff == 0 || colDiff == 0 || abs(filaDiff) == abs(colDiff)) {
        int stepFila = (filaDiff == 0) ? 0 : (filaDiff / abs(filaDiff));
        int stepCol = (colDiff == 0) ? 0 : (colDiff / abs(colDiff));

        int currentFila = this->pos.fila + stepFila;
        int currentCol = this->pos.columna + stepCol;

        while (currentFila != destino.fila || currentCol != destino.columna) {
            Posicion casillaIntermedia = {currentFila, currentCol};
            if (tablero.getPieza(casillaIntermedia) != nullptr) {
                return false;
            }
            currentFila += stepFila;
            currentCol += stepCol;
        }

        Pieza* piezaEnDestino = tablero.getPieza(destino);
        return piezaEnDestino == nullptr || piezaEnDestino->getColor() != this->color;
    }

    return false;
}

string Reina::getSimbolo() const {
    if (this->color == Color::BLANCO) {
        return "QB";
    } else {
        return "RN";
    }
}