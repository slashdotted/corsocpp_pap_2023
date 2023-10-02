#include "Frazione.h"
#include <iostream>

// con Frazione:: dichiaro che il metodo stampa
// che sto implementando è quello di Frazione
void Frazione::stampa() {
    // visto che sono nello scope di Frazione posso
    // accedere direttamente ai campi
    std::cout <<
        numeratore << "/" << denominatore << "\n";
    // this c'è anche in C++ ma è un puntatore
    // quindi va dereferenziato per accedere ai membri
    // o devo usare ->
    std::cout <<
        this->numeratore << "/" << this->denominatore << "\n";
}

// Come in Java il costruttore è un metodo che ha
// lo stesso nome della classe
Frazione::Frazione(int num, int den) {
    if (den == 0) {
        denominatore = 1;
    } else {
        denominatore = den;
    }
    numeratore = num;
}

