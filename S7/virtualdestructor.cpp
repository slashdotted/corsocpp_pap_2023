#include <iostream>
#include <vector>
using namespace std;

class Figura {
public:
    virtual ~Figura() {
        cout << "Destroying Figura" << endl;
    }
};

class Rettangolo : public Figura {
public:
    // Per brevità non applico la regola dei tre
    Rettangolo() : m_intptr { new int } {};
    ~Rettangolo() {
        cout << "Destroying Rettangolo" << endl;
        delete m_intptr;
    }
private:
    int* m_intptr;
};

class Cerchio : public Figura {
public:
    // Per brevità non applico la regola dei tre
    Cerchio() : m_intptr { new int } {};
    ~Cerchio() {
        cout << "Destroying Cerchio" << endl;
        delete m_intptr;
    }
private:
    int* m_intptr;
};

class GestoreFigure {
public:
    GestoreFigure() {}

    ~GestoreFigure() {
        for(auto f : m_figure) {
            delete f;
        }
    }

    void aggiungi(Figura* f) {
        m_figure.push_back(f);
    }
private:
    std::vector<Figura*> m_figure;

};
int main() {
    GestoreFigure gf;
    gf.aggiungi(new Rettangolo);
    gf.aggiungi(new Rettangolo);
    gf.aggiungi(new Cerchio);
}
