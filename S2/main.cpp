#include <string>
#include <iostream>

// In questa lezione abbiamo visto:
// - i problemi legati all'allocazione dinamica (memory leak) e il motivo per il quale
//   si preferisce allocare sullo stack in C++ (quando possibile). In C++ quello che
//   si alloca sullo stack viene liberato automaticamente, risulta perciò vantaggioso
//   sfruttare lo stack. Snippet di codice tipici in Java, dove abbiamo un'allocazione
//   all'inizio della funzione con new (e una deallocazione alla fine), come in fun e funAllaJava
//   sono da riscrivere utilizzando lo stack (come in funAllaCPP)
// - le situazioni in cui siamo confrontati con i puntatori in C (e in C++), ovvero:
//      - quanto allochiamo dinamicamente la memoria (malloc e new ritornano dei puntatori)
//      - quando vogliamo passare dei parametri senza copiarli (es. swap)
//      - quando vogliamo modificare delle variabili a partire da una funzione
//   Queste situazioni presentano diverse problematiche, nello specifico:
//      - è necessario dereferenziare i puntatori
//      - la dereferenzazione di un puntatore non valido porta tipicamente a un crash
//   Come alternativa ai puntatori, C++ mette a disposizione dei riferimenti, che
//   indicano degli alias verso altre variabili. I riferimenti non devono essere
//   dereferenziati, e possono risolvere in modo elegante il problema del passaggio
//   di parametri senza copia.
//   Il passaggio per riferimento è possibile solo per parametri di tipo l-value
//   (valori NON temporanei). Per passare valori temporanei devo sottoscrivere un
//   contratto con il compilatore introducendo il vincolo const.
//   Infine abbiamo visto come usare i riferimenti per iterare su un array senza
//   copiare gli elementi.



// Puntatori a memoria allocata dinamicamente
void fun(int i) {
    int *number{new int{42}};
    if (i > 0) {
        return;
    }
    delete number; // devo ricordarmi di deallocare
}

// Esempio di allocazione dinamica "non necessario"
// La memoria allocata all'inizio della funzione viene
// deallocata alla fine della funzione
// --> preferibile usare lo stack!
void funAllaJava() {
    // String warning = new String("Hey");
    std::string *warning{new std::string{"Hey"}};
    // ...
    (*warning).append("ciao");
    // ...
    delete warning;
}

// Soluzione "alla CPP" che usa lo stack
void funAllaCPP() {
    std::string warning{"Hey"};
    // ...
}

// Swap con puntatori
void swap(int *a, int *b) {
    int temp{*a}; // <- è necessario dereferenziare
    *a = *b;
    *b = temp;
}

// Swap con riferimenti
// a e b sono riferimenti/alias a variabili
// nel contesto del chiamante
void swap(int& a, int& b) {
    int temp{a};
    a = b;
    b = temp;
}

struct Persona {
    std::string nome;
    std::string cognome;
    int cap;
};

// Inizializzazione di una struttura tramite puntatore
// Passo il puntatore per inizializzare un
// oggetto che arriva da "fuori"
void inizializzaPersona(Persona *x) {
    x->nome = "Pietro";
    x->cognome = "Gambadilegno";
    x->cap = 6900;
}

// Inizializzazione di una struttura tramite riferimento
// x è un riferimento/alias di un oggetto
// che sta fuori "fuori"
void inizializzaPersona(Persona& x) {
    x.nome = "Pippo";
    x.cognome = "Topolino";
    x.cap = 6600;
}

// Passaggio per valore (copia)
// È possibile sia con l-value che con r-value
void calcola(int s) {
    // ...
}

// Passaggio per riferimento
// È possibile solo con l-value
void calcola_per_riferimento(int& s) {
    // ...
}

// Passaggio per riferimento const
// È possibile solo con l-value che con r-value
void calcola_per_riferimento_const(const int& s) {
    // ...
}

// Ritorna un valore temporaneo
int getInt() {
    return 42;
}

// Ritorna un riferimento a una variabile locale: ERRORE!
double& getDouble() {
    double pi{3.14};
    return pi;
}

// Ritorna un riferimento a una variabile sullo heap
double& getDouble2() {
    double *pi{new double{3.14}};
    return *pi;
}

// Ritorna un riferimento ricevuto in input
double& getDouble(double& x) {
    return x;
}

// Ritorna un riferimento ricevuto in input
const double& getMax(const double& x, const double& y) {
    return x>y ? x : y;
}

int main() {
    std::string msg{"Messaggio"}; // Stack
    int anno{2023}; // Stack

    std::string *amsg{new std::string{"Altro messaggio"}}; // Heap

    delete amsg;

    int x{5};
    int y{7};

    int temp{x};
    x = y;
    y = temp;

    int *w;
    int *q;

    swap(&x,&y);
    //swap(w,q);
    swap(x,y); // overload con riferimenti
    // x = 7, y = 5

    Persona p;
    inizializzaPersona(&p);
    inizializzaPersona(p); // overload con riferimento

    int& alias_per_x{x};
    int& alias_per_y{y};

    calcola(x);
    calcola(42);
    calcola(getInt());

    // x è l-value (può stare a sinistra di un assegnamento)
    calcola_per_riferimento(x);
    // 42 è r-value (può stare solo a destra di un assegnamento)
    //calcola_per_riferimento(42); // non posso passare per riferimento 42
    // getInt() è r-value (può stare solo a destra di un assegnamento)
    //calcola_per_riferimento(getInt()); // non posso per riferimento un valore temporaneo
    calcola_per_riferimento_const(42);
    calcola_per_riferimento_const(getInt());

    const double& valore{getDouble()};

    std::cout << "Il valore è:\n";
    // std::cout << valore << '\n'; // Errore! valore referenzia un dato locale della funzione

    // Utilizzo dei riferimenti per iterare su un array senza copiare gli
    // elementi
    int array[] {1,2,3,4,5,6};
    for(int i : array) { // copia un elemento alla volta in i
        std::cout << i << '\n';
    }
    for(int& i : array) { // non copio gli elementi, posso modificarli
        i += 2;
    }
    for(const int& i : array) { // non copio gli elementi
        std::cout << i << '\n';
    }
}
