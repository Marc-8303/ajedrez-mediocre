#pragma once
#include "Pieza.h"

class Torre : public Pieza {
public:
    Torre(const Color& color, const Posicion& pos);
    bool movimientovalido(const Posicion& destino, const Tablero& tablero) const override;
    string getSimbolo() const override;
};
