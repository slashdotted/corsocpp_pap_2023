#include <vector>
#include <string>
#include <iostream>


struct Persona {
    Persona(std::string n) : nome{n} {}
    std::string nome;
};

struct Team {

    void aggiungi(Persona p) {
        membri.push_back(p);
    } 

private:
    std::vector<Persona> membri;

};

struct Team2 : private std::vector<Persona> {
    void aggiungi(Persona p) {
        push_back(p);
    }
};

struct A {
    virtual ~A() noexcept {
        std::cout << "Distruggo A\n";
    }
};

struct B : A {
    ~B() noexcept override {
        std::cout << "Distruggo B\n";
        delete x;
    }

    int* x;
};


int main() {
    Team t;
    t.aggiungi(Persona{"Aldo"});
    t.aggiungi(Persona{"Giovanni"});
    Team2 t2;
    t2.aggiungi(Persona{"Aldo"});
    t2.aggiungi(Persona{"Giovanni"});
    //t2.push_back(Persona{"Giacomo"});

    B *b{new B};
    A *a{b};

    delete a;


}
