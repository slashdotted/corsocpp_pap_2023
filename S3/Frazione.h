#ifndef FRAZIONE_H
#define FRAZIONE_H

// Dichiarazione di una "classe" con struct
struct Frazione {
    double valore; // Il livello di accesso predefinito è public!
private: // "Apre" una sezione private
    int numeratore;
    int denominatore;
public: // "Apre" una sezione public

    // Metodo
    void stampa();

    // Come in Java il costruttore è un metodo che ha
    // lo stesso nome della classe
    Frazione(int num, int den);

protected: // "Apre" una sezione protected
    // ..
};

#endif // FRAZIONE_H
