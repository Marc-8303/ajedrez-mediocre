#include "../include/Pieza.h"

Pieza::Pieza(Color color, TipoPieza tipo, const Posicion &pos)
    : color(color), tipo(tipo), pos(pos), seHaMovido(false) {}

Color Pieza::getColor() const { return color; }

TipoPieza Pieza::getTipo() const { return tipo; }

Posicion Pieza::getPosicion() const { return pos; }

bool Pieza::yaSeMovio() const { return seHaMovido; }

void Pieza::setPosicion(const Posicion &nuevaPos) { 
    this->pos = nuevaPos; 
}

void Pieza::setMovido(bool movido) { 
    this->seHaMovido = movido; 
}