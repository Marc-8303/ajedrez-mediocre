#pragma once
#include "Pieza.h"

class Caballo : public Pieza {
public:
    Caballo(const Color& color, const Posicion& pos);

    bool movimientovalido(const Posicion& destino, const Tablero& tablero) const override;
    
    string getSimbolo() const override;
};
