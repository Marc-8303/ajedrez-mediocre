#pragma once
#include "Pieza.h"

class Peon : public Pieza {
public:
    Peon(const Color& color, const Posicion& pos);
    bool movimientovalido(const Posicion& destino, const Tablero& tablero) const override;
    string getSimbolo() const override;
};
