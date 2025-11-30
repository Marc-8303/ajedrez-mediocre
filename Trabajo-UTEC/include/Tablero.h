#pragma once
#include <vector>

#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Pieza.h"
#include "Extra.h"

using namespace std;

class Tablero {
private:
    vector<vector<Pieza*>> casillas;

public:
    Tablero();
    ~Tablero(); // Destructor para limpiar memoria
    void inicializar();
    void imprimir() const;
    Pieza* getPieza(const Posicion& pos) const;
    void moverPieza(const Posicion& origen, const Posicion& destino);
    void colocarPieza(Pieza* pieza, const Posicion& pos);

    Pieza* quitarPieza(const Posicion& pos);

};