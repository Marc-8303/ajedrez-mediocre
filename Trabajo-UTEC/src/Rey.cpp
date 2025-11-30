#include "../include/Rey.h"
#include "../include/Tablero.h"

/*

Pieza: Rey
- Movimiento: Se mueve una casilla en cualquier direccion
- Captura: El rey captura una pieza enemiga moviéndose a la casilla ocupada por esa pieza.
- Restricciones: No puede moverse a una casilla que esté bajo ataque enemigo.

*/

Rey::Rey(const Color& color, const Posicion& pos)
    : Pieza(color, TipoPieza::REY, pos) {}

bool Rey::movimientovalido(const Posicion& destino, const Tablero& tablero) const {
    int filaDiff = destino.fila - this->pos.fila;
    int colDiff = destino.columna - this->pos.columna;

    // --- 1. Movimiento normal de una casilla ---
    // La condición (filaDiff != 0 || colDiff != 0) evita el "no-movimiento"
    if ((abs(filaDiff) <= 1 && abs(colDiff) <= 1) && (filaDiff != 0 || colDiff != 0)) {
        Pieza* piezaDestino = tablero.getPieza(destino);
        // Es válido si el destino está vacío o tiene un enemigo
        return piezaDestino == nullptr || piezaDestino->getColor() != this->color;
    }

    // --- 2. Lógica del Enroque (Castling) ---
    // El enroque es un movimiento de 2 casillas horizontales
    if (filaDiff == 0 && abs(colDiff) == 2) {
        // Para hacer enroque, el rey NO debe haberse movido antes
        if (this->yaSeMovio()) {
            return false;
        }

        // Determinar si es enroque corto (hacia la derecha) o largo (hacia la izquierda)
        Posicion posTorre;
        if (colDiff == 2) { // Enroque corto
            posTorre = {this->pos.fila, 7}; // Columna H
        } else { // Enroque largo (colDiff == -2)
            posTorre = {this->pos.fila, 0}; // Columna A
        }
        
        Pieza* torre = tablero.getPieza(posTorre);
        
        // Validaciones del enroque según el PDF:
        // a) Debe haber una torre en la esquina
        // b) La torre no debe haberse movido
        if (torre == nullptr || torre->getTipo() != TipoPieza::TORRE || torre->yaSeMovio()) {
            return false;
        }

        // c) El camino entre el rey y la torre debe estar despejado
        int paso = colDiff / abs(colDiff); // +1 para corto, -1 para largo
        for (int c = this->pos.columna + paso; c != posTorre.columna; c += paso) {
            if (tablero.getPieza({this->pos.fila, c}) != nullptr) {
                return false; // Camino bloqueado
            }
        }

        // Si todas las condiciones se cumplen, el enroque es válido.
        // El PDF simplifica: no es necesario verificar si el rey pasa por jaque.
        return true;
    }
    
    // Si no es un movimiento de 1 casilla ni un enroque, es inválido.
    return false;
}

string Rey::getSimbolo() const {
    if (this->color == Color::BLANCO) {
        return "KB";
    } else {
        return "KN";
    }
}