// Come in C posso definire dei tipi "utente"

// Con "enum"
// il typedef non è necessario in C++
enum Colore {
   Rosso, Giallo, Verde
};

// Con "enum class"
// è come "enum" ma non avviene la conversione
// automatica a un tipo aritmetico
enum class Color {
    Red, Yellow, Green
};

void cambiaColore(Colore c) {
}

void changeColor(Color c) {
}

// "struct"
// typedef non necessario in C++
struct Persona {
   // ...
};

int main() {
    cambiaColore(Colore::Rosso);
    changeColor(Color::Green);

    // Creo un'istanza della struct Persona
    // Notare che è possibile usare direttamente Persona
    Persona p;

    int c1{Rosso}; // la conversione da Colore a int è possibile
    Colore c2{Verde};
    if (c2 == 3) { // la conversione da Colore a int è possibile
        // ..
    }

    // int c3{Red}; // la conversione da Color a int NON è possibile
    Color c4{Color::Green};
    /*if (c4 == 3) { // la conversione da Colore a int NON è possibile
        // ..
    }*/

}
