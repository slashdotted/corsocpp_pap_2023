#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

struct Appunti {

    Appunti(const std::string& titolo) : m_titolo{new std::string{titolo}} {
        std::cout << "Construisco Appunti " << *m_titolo << "\n";
    }

    virtual ~Appunti() {
        if (m_titolo) {
            std::cout << "Distruttore Appunti " << *m_titolo << "\n";
        } else {
            std::cout << "Distruttore Appunti vuoti"<< "\n";
        }
        delete m_titolo;
    }

    // ***************************************
    // COPIA
    // ***************************************
    // Allocazione di memoria + copia
    Appunti(const Appunti& o) : m_titolo{new std::string{*o.m_titolo}} {
        std::cout << "Costruttore di copia di Appunti " << *m_titolo << "\n";
        sleep(3);
    }

    Appunti& operator=(const Appunti& a) {
        // Copia
        *m_titolo = *a.m_titolo;
        std::cout << "Operatore di assegnamento di copia di Appunti " << *m_titolo << "\n";
        sleep(3);
        return *this;
    }

    // ***************************************
    // SPOSTAMENTO
    // ***************************************
                           // "Rubo" l'allocazione da o
    Appunti(Appunti&& o) : m_titolo{std::move(o.m_titolo)} {
        // Invalido il puntatore in o
        o.m_titolo = nullptr;
        std::cout << "Costruttore di spostamento di Appunti " << m_titolo << "\n";
    }

    Appunti& operator=(Appunti&& a) {
        // Libero la mia allocazione
        delete m_titolo;
        // Rubo l'allocazione di a
        m_titolo = std::move(a.m_titolo);
        a.m_titolo = nullptr;
        std::cout << "Operatore di assegnamento di spostamento di Appunti " << m_titolo << "\n";
        return *this;
    }

private:
    std::string *m_titolo;
};

struct Studente {
    void prendi_appunti(const Appunti& a) {
        m_appunti = a;
        std::cout << "Ho preso gli appunti (l-value)\n";
    }

    void prendi_appunti(Appunti&& a) {
        m_appunti = std::move(a);
        std::cout << "Ho preso gli appunti (r-value)\n";
    }
private:
    Appunti m_appunti{"Personali"};
};

Appunti scrivi_appunti() {
    Appunti a{"Linguaggi"};
    return a;
}

int main() {
    Studente luca;
    std::cout << "==============================" << std::endl;
    luca.prendi_appunti(scrivi_appunti());
    std::cout << "==============================" << std::endl;
    Appunti b{"Parallela"};
    luca.prendi_appunti(b);
    std::cout << "==============================" << std::endl;
    std::vector<Appunti> m_raccolta;
    Appunti c{"Microcontrollori"};
    m_raccolta.push_back(std::move(c));
    m_raccolta.push_back(Appunti{"Microcontrollori"});
    m_raccolta.push_back(scrivi_appunti());
}






