// src/Partida.cpp
#include "../include/Partida.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype> // para toupper()

// Incluir las piezas necesarias para la coronación
#include "../include/Reina.h"
#include "../include/Torre.h"
#include "../include/Alfil.h"
#include "../include/Caballo.h"
#include "../include/Extra.h"

using namespace std;

// constructor

Partida::Partida() : turnoActual(Color::BLANCO), juegoTerminado(false) {
}

void Partida::iniciar() {
    tablero.inicializar();
    buclePrincipal();
}

void Partida:: buclePrincipal(){
    while(!juegoTerminado){
        mostrarEstadoJuego();
        procesarTurno();
    }
}

void Partida::mostrarEstadoJuego() {
    tablero.imprimir();
    cout << "Turno de: " << (turnoActual == Color::BLANCO ? "Blancas" : "Negras") << endl;
}

void Partida::procesarTurno() {
    string origen, destino;
    cout << "Ingrese movimiento (ej: E2 E4): ";
    cin >> origen >> destino;

    if (procesarMovimiento(origen, destino)) {
        turnoActual = (turnoActual == Color::BLANCO) ? Color::NEGRO : Color::BLANCO;
    } else {
        cout << "Movimiento invalido. Intente de nuevo." << endl;
    }
}

bool Partida::procesarMovimiento(const string& origenStr, const string& destinoStr) {
    // Convertir strings a coordenadas
    // Asumimos formato "E2" -> columna 'E', fila '2'
    if (origenStr.length() != 2 || destinoStr.length() != 2) return false;

    int colOrigen = toupper(origenStr[0]) - 'A';
    int filaOrigen = origenStr[1] - '1';
    int colDestino = toupper(destinoStr[0]) - 'A';
    int filaDestino = destinoStr[1] - '1';

    // Validar rangos
    if (colOrigen < 0 || colOrigen > 7 || filaOrigen < 0 || filaOrigen > 7 ||
        colDestino < 0 || colDestino > 7 || filaDestino < 0 || filaDestino > 7) {
        return false;
    }

    Posicion origen = {filaOrigen, colOrigen};
    Posicion destino = {filaDestino, colDestino};

    Pieza* pieza = tablero.getPieza(origen);

    // 1. Verificar que hay una pieza y es del color del turno actual
    if (pieza == nullptr || pieza->getColor() != turnoActual) {
        return false;
    }

    // 2. Verificar movimiento válido de la pieza
    if (!pieza->movimientovalido(destino, tablero)) {
        return false;
    }

    // 3. Manejar Enroque (Caso especial del Rey)
    if (pieza->getTipo() == TipoPieza::REY && abs(colDestino - colOrigen) == 2) {
        if (!gestionarEnroque(origen, destino)) {
            return false;
        }
    }

    // 4. Ejecutar movimiento normal
    tablero.moverPieza(origen, destino);

    // 5. Manejar Coronación (Peón llega al final)
    if (pieza->getTipo() == TipoPieza::PEON) {
        if ((pieza->getColor() == Color::BLANCO && filaDestino == 7) ||
            (pieza->getColor() == Color::NEGRO && filaDestino == 0)) {
            gestionarCoronacion(destino);
        }
    }

    return true;
}

void Partida::gestionarCoronacion(const Posicion& pos) {
    cout << "Coronacion! Elija pieza (Q: Reina, T: Torre, C: Caballo, A: Alfil): ";
    char opcion;
    cin >> opcion;
    opcion = toupper(opcion);

    Pieza* piezaCreada = nullptr;
    Color color = turnoActual; // La pieza coronada es del color actual

    switch (opcion) {
        case 'T': piezaCreada = new Torre(color, pos); break;
        case 'C': piezaCreada = new Caballo(color, pos); break;
        case 'A': piezaCreada = new Alfil(color, pos); break;
        case 'Q': 
        default:  piezaCreada = new Reina(color, pos); break;
    }

    tablero.colocarPieza(piezaCreada, pos);
}

bool Partida::gestionarEnroque(const Posicion& origen, const Posicion& destino) {
    int fila = origen.fila;
    bool enroqueCorto = (destino.columna > origen.columna);
    
    Posicion posTorreOrigen = {fila, enroqueCorto ? 7 : 0};
    Posicion posTorreDestino = {fila, enroqueCorto ? 5 : 3}; // F o D

    // Mover la torre
    tablero.moverPieza(posTorreOrigen, posTorreDestino);
    return true;
}