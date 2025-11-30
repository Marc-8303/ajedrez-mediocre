#pragma once
#include "Pieza.h"

class Alfil : public Pieza {
public:
  Alfil(const Color &color, const Posicion &pos);
  bool movimientovalido(const Posicion &destino,
                        const Tablero &tablero) const override;
  string getSimbolo() const override;
};
