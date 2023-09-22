// gli header della libreria standard non hanno estensione
#include <iostream>
// per poter utilizzare il tipo "string" devo includere
// l'header corrispondente
#include <string>

#include "math.h"

// con "using namespace xxx" importo tutte le definizioni del namespace
// xx nel namespace globale
// using namespace std;

// con "using yyy" importo solo un simbolo specifico nel namespace,
// in questo caso std::cout
using std::cout;

// come in C è necessario usare delle forward declarations / dichiarare
// i prototipi delle funzioni se voglio poterle utilizzare prima che
// nel codice appaia l'implementazione
void fun(int);
void fun(double);
// se una funzione dichiara dei parametri con valori di default
// questi vanno messi nel prototipo e NON dove ho l'implementazione
// (vale anche se separo dichiarazione e implementazione in .h e .cpp: i
// valori per default vanno nel .h)
int dividi(int x, int y=1, int z=1, int a=1);

// con "namespace zzz" dichiaro un namespace (che si "estende" tra le
// parentesi graffe)
namespace programma {

// Le dichiarazioni / definizioni all'interno di questo namespace
// possono essere utilizzate attraverso il prefisso programma::

// Soluzione "alla Java" per l'implementazione di una funzione
// che accetta 2,3, oppure 4 parametri
// Nota: C++ (come Java) supporta l'overloading
int somma(int x, int y, int z, int a) {
    return x+y+z+a;
}

int somma(int x, int y, int z) {
    //return x+y+z;
    return somma(x,y,z,0);
}

int somma(int x, int y) {
    //cout << "Richiamo somma" << std::endl;
    //fun(4);
    //return x+y;
    return somma(x,y,0,0);
}

// Soluzione "alla C++" per l'implementazione di una funzione
// che accetta 2,3, oppure 4 parametri: i parametri "opzionali" ricevono
// un valore di default. I parametri opzionali vanno sempre messi
// dopo quelli obbligatori (che sono quelli che non hanno un valore
// di default)
int moltiplica(int x, int y=1, int z=1, int a=1) {
    return x*y*z*a;
}

}

// Attenzione alle ambiguità: se utilizzo la funzione dividi
// con due argomenti entrambe le varianti che seguono sono
// possibili (errore!)

// I parametri y, z, e a hanno un valore di default, quindi
// possono essere omessi
int dividi(int x, int y, int z, int a) {
    return x/y/z/a;
}

int dividi(int a, int b) {
    return a/b;
}

// L'overload è possibile solo "variando" i tipi/il numero
// degli argomenti
void fun(int i) {
    // ..
}
// ...perciò questo non è un overload valido
/*int fun(int i) {

}*/
// ...mentre questo sì
void fun(double d) {
    // ..
}

using programma::somma; // importa somma dal namespace programma a quello globale
namespace ma = math::arithmetics; // crea un alias per il namespace
// da questo punto posso usare ma::... invece di math::arithmetics::...

auto miasomma(int i, int j) {
    return i+j;
}

int main()
{
    // cout rappresenta lo standard output (simile a System.out di Java)
    // l'operatore << è sovraccaricato ed è usato per scrivere sullo
    // standard output (posso vederlo come una freccia << che va verso
    // lo standard output)
    // endl rappresenta il carattere di ritorno a capo e un "flush" dell'output
    cout << "Hello World!" << std::endl;
    cout << "5+4=" << somma(5,4) << std::endl;
    cout << "5+4=" << math::arithmetics::somma(5,4) << std::endl;
    cout << "5+4=" << ma::somma(5,4) << std::endl;

    cout << "2*3*4*5=" << programma::moltiplica(2,3,4,5) << std::endl;
    cout << "2*3*4=" << programma::moltiplica(2,3,4) << std::endl;
    cout << "2*3=" << programma::moltiplica(2,3) << std::endl;
    cout << "2=" << programma::moltiplica(2) << std::endl;

    dividi(7,3,6);
    // dividi(7,3); // ambiguo

    // Da C++11 si preferisce inizializzare le variabili con {}
    // In C++ è presente un tipo stringa (parte del namespace std)
    std::string msg{"Hello"};
    // string è mutabile e permette di concatenare stringhe in modo semplice
    msg += " world!";
    msg = msg + "!!!!";
    // Il confronto tra stringhe viene fatto con ==
    if (msg == "Hello world!!!!!") {
        // ..
    }

    std::string msg2 = "Ciao";

    // Inizializzazione di una variabile
    int i = 3; // stile C
    int j(8); // stile C++ pre-11
    int k{5}; // da C++11

    int i2 = 3.14;
    int j2(3.14);
    //int k2{3.14};

    // Attenzione alle differenze con Java
    std::string m; // Istanzia un oggetto di tipo string sullo stack
    std::string *m2{new std::string}; // Istanzia un oggetto di tipo string sullo heap

    // std::string n{new std::string}; // Errore!

    auto pi{3.14};
    auto messaggio{"hello world"};
    m = "ciaò";
    std::cout << m << " -> " << m.size() << '\n';
    //std::cout << m[0] << m[1] << m[2] << m[3] << m[4] << '\n';
    const char* cm{m.c_str()}; // Posso "estrarre" una stringa C da string
    // con auto il tipo della variabile viene determinato automaticamente
    auto l{7};
    auto q{8};
    auto z{miasomma(l,q)};

    delete m2;
    return 0;
}
