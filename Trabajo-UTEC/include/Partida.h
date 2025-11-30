#pragma once
#include "Extra.h"
#include "Tablero.h"

using namespace std;

class Partida {
private:
    Tablero tablero;
    Color turnoActual;
    bool juegoTerminado;
public:
    Partida();
    void iniciar();
    void buclePrincipal();

private:
    void mostrarMenuPrincipal();
    void mostrarEstadoJuego();
    void procesarTurno();

    bool procesarMovimiento(const string& origenStr, const string& destinoStr);
    
    void gestionarCoronacion(const Posicion& pos);
    bool gestionarEnroque(const Posicion& origen, const Posicion& destino);
    
};
