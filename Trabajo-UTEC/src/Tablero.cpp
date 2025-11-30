#include "../include/Tablero.h"
#include <iostream>

#include "../include/Peon.h"
#include "../include/Torre.h"
#include "../include/Caballo.h"
#include "../include/Alfil.h"
#include "../include/Reina.h"
#include "../include/Rey.h"
#include "../include/Extra.h"

using namespace std;

// Constructor del Tablero
Tablero::Tablero() {
    casillas.resize(8);
    for (int i = 0; i < 8; ++i) {
        casillas[i].resize(8, nullptr);
    }
}

// Destructor del Tablero
Tablero::~Tablero() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (casillas[i][j] != nullptr) {
                delete casillas[i][j];
                casillas[i][j] = nullptr;
            }
        }
    }
}

void Tablero::inicializar(){
    // Limpiar tablero si ya tenía piezas
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if (casillas[i][j] != nullptr) {
                delete casillas[i][j];
                casillas[i][j] = nullptr;
            }
        }
    }

    for (int j = 0; j < 8; ++j) {
        casillas[1][j] = new Peon(Color::BLANCO, Posicion{1, j});
    }

    // Torres Blancas
    casillas[0][0] = new Torre(Color::BLANCO, Posicion{0, 0});
    casillas[0][7] = new Torre(Color::BLANCO, Posicion{0, 7});
    // Caballos Blancos
    casillas[0][1] = new Caballo(Color::BLANCO, Posicion{0, 1});
    casillas[0][6] = new Caballo(Color::BLANCO, Posicion{0, 6});
    // Alfiles Blancos
    casillas[0][2] = new Alfil(Color::BLANCO, Posicion{0, 2});
    casillas[0][5] = new Alfil(Color::BLANCO, Posicion{0, 5});
    // Reina y Rey Blancos
    casillas[0][3] = new Reina(Color::BLANCO, Posicion{0, 3});
    casillas[0][4] = new Rey(Color::BLANCO, Posicion{0, 4});

    // --- Colocar Piezas Negras ---
    // Peones Negros (fila 7, índice 6)
    for (int j = 0; j < 8; ++j) {
        casillas[6][j] = new Peon(Color::NEGRO, Posicion{6, j});
    }
    // Torres Negras
    casillas[7][0] = new Torre(Color::NEGRO, Posicion{7, 0});
    casillas[7][7] = new Torre(Color::NEGRO, Posicion{7, 7});
    // Caballos Negros
    casillas[7][1] = new Caballo(Color::NEGRO, Posicion{7, 1});
    casillas[7][6] = new Caballo(Color::NEGRO, Posicion{7, 6});
    // Alfiles Negros
    casillas[7][2] = new Alfil(Color::NEGRO, Posicion{7, 2});
    casillas[7][5] = new Alfil(Color::NEGRO, Posicion{7, 5});
    // Reina y Rey Negros
    casillas[7][3] = new Reina(Color::NEGRO, Posicion{7, 3});
    casillas[7][4] = new Rey(Color::NEGRO, Posicion{7, 4});

}

void Tablero::imprimir() const{
    cout << endl;
    cout << "    A   B   C   D   E   F   G   H" << endl;
    for (int i = 7; i >= 0; --i) { // Iterar desde la fila 8 (índice 7) hacia abajo
        std::cout << " " << i + 1 << " ";
        for (int j = 0; j < 8; ++j) {
            std::cout << "[";
            if (casillas[i][j] != nullptr) {
                // Llama al getSimbolo() polimórfico de la pieza
                std::cout << casillas[i][j]->getSimbolo();
            } else {
                std::cout << "  "; // Dos espacios para casillas vacías
            }
            std::cout << "]";
        }
        std::cout << " " << i + 1 << "\n";
    }
    std::cout << "    A   B   C   D   E   F   G   H\n\n";
}

// Obtener una pieza
Pieza* Tablero::getPieza(const Posicion& pos) const{
    return casillas[pos.fila][pos.columna];
}

// Mover una pieza

void Tablero::moverPieza(const Posicion& origen, const Posicion& destino) {
    // Si hay una pieza en el destino, eliminarla (captura)
    if (casillas[destino.fila][destino.columna] != nullptr) {
        delete casillas[destino.fila][destino.columna];
    }

    casillas[destino.fila][destino.columna] = casillas[origen.fila][origen.columna];
    casillas[origen.fila][origen.columna] = nullptr;

    Pieza* piezaMovida = getPieza(destino);
    if (piezaMovida != nullptr) {
        piezaMovida->setPosicion(destino);
        piezaMovida->setMovido(true);
    }

}

void Tablero::colocarPieza(Pieza* pieza, const Posicion& pos) {
    if(pieza != nullptr){
        // Si hay algo en la posición, eliminarlo primero
        if (casillas[pos.fila][pos.columna] != nullptr) {
            delete casillas[pos.fila][pos.columna];
        }

        pieza ->setPosicion(pos);
        pieza -> setMovido(true);
        casillas[pos.fila][pos.columna] = pieza;
    }
}


Pieza* Tablero::quitarPieza(const Posicion& pos) {
    Pieza* p = casillas[pos.fila][pos.columna];
    casillas[pos.fila][pos.columna] = nullptr;
    return p;
}
