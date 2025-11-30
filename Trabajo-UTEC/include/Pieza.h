#pragma once

#include <string>
#include "Extra.h"

using namespace std;


class Tablero;

class Pieza {
protected:
    Color color;
    TipoPieza tipo;
    Posicion pos;
    bool seHaMovido;

public:
    Pieza(Color color, TipoPieza tipo, const Posicion& pos);

    virtual ~Pieza( ) = default;

    virtual bool movimientovalido(const Posicion& destino, const Tablero& tablero) const = 0;

    virtual string getSimbolo() const = 0;

    // Getters:
    Color getColor() const;
    TipoPieza getTipo() const;
    Posicion getPosicion() const;
    bool yaSeMovio() const;

    // Setters:
    void setPosicion(const Posicion& nuevaPos);
    void setMovido(bool movido);
};