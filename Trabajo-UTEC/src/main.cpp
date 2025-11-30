#include <iostream>
#include "../include/Partida.h"

using namespace std;



void mostrarMenu() {
    cout << "---- Ajedrez ----" << endl;
    cout << "1. Jugar (J vs J)" << endl;
    cout << "2. Instrucciones" << endl;
    cout << "3. Mostrar Integrantes" << endl;
    cout << "4. Consideraciones (Reglas especiales)" << endl;
    cout << "0. Salir" << endl;
}


void mostrarInstrucciones() {
    cout << endl;
    cout << "Instrucciones del juego de Ajedrez:" << endl;
    cout << "1. El objetivo del juego es dar jaque mate al rey del oponente." << endl;
    cout << "2. Cada tipo de pieza tiene movimientos específicos." << endl;
    cout << "3. El juego termina cuando un jugador da jaque mate al rey del oponente." << endl;
    cout << "4. Para mover una pieza, ingrese las coordenadas de origen y destino." << endl;
    cout << "5. Disfrute del juego!" << endl;
    cout << endl;
}

void mostrarIntegrantes() {
    cout << endl;
    cout << "Integrantes del equipo:" << endl;
    cout << "1. Integrante 1" << endl;
    cout << "2. Integrante 2" << endl;
    cout << "3. Integrante 3" << endl;
    cout << endl;
}

void mostrarConsideraciones() {
    cout << endl;
    cout << "Consideraciones y reglas especiales del Ajedrez:" << endl;
    cout << "1. Enroque: Movimiento especial que involucra al rey y una torre." << endl;
    cout << "2. Captura al paso: Movimiento especial para peones." << endl;
    cout << "3. Promoción de peones: Cuando un peón alcanza la fila más lejana, puede convertirse en otra pieza." << endl;
    cout << "4. Jaque y jaque mate: Situaciones especiales que afectan el estado del juego." << endl;
    cout << endl;
}

int main(){
    int opcion;
    bool salir = false;

    do{
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1: {
                cout << "Iniciando una nueva partida..." << endl;
                Partida partida;
                partida.iniciar();

                cout << "Partida finalizada." << endl;
                break;
            }
            case 2:
                mostrarInstrucciones();
                break;
            case 3:
                mostrarIntegrantes();
                break;
            case 4:
                mostrarConsideraciones();
                break;
            case 0:
                salir = true;
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }
    } while (!salir);

    return 0;
}