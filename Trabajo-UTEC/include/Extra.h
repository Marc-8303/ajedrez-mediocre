#pragma once

enum class Color{
    BLANCO,
    NEGRO,
    NINGUNO
};

enum class TipoPieza{
    PEON,
    TORRE,
    CABALLO,
    ALFIL,
    REINA,
    REY,
    VACIO
};

struct Posicion {
    int fila;
    int columna;
};