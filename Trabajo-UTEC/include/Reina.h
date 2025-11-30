#pragma once
#include "Pieza.h"

class Reina : public Pieza {
public:
    Reina(const Color& color, const Posicion& pos);
    bool movimientovalido(const Posicion& destino, const Tablero& tablero) const override;
    string getSimbolo() const override;
};
