#pragma once
#include "Pieza.h"

class Rey : public Pieza {
public:
    Rey(const Color& color, const Posicion& pos);
    bool movimientovalido(const Posicion& destino, const Tablero& tablero) const override;
    string getSimbolo() const override;
};
