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
    Rettangolo() : m_intptr { new int } {};
    ~Rettangolo() {
        cout << "Destroying Rettangolo" << endl;
        delete m_intptr;
    }
    Rettangolo(const Rettangolo&) = delete;
    Rettangolo& operator=(const Rettangolo&) = delete;
private:
    int* m_intptr;
};

class Cerchio : public Figura {
public:
    Cerchio() : m_intptr { new int } {};
    ~Cerchio() {
        cout << "Destroying Cerchio" << endl;
        delete m_intptr;
    }
    Cerchio(const Cerchio&) = delete;
    Cerchio& operator=(const Cerchio&) = delete;
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

    Rettangolo r1, r2;
    //r1 = r2; // Errore! L'operatore = è stato cancellato
}
