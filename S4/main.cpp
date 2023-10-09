#include <string>
#include <iostream>

struct Titolo {
    Titolo(const std::string& t) : m_t{t} {
        std::cout << "Costruzione Titolo(" << t <<")\n";
    }
    std::string m_t;
};

struct Autore {
    Autore(const std::string& nome, const std::string cognome)
        : m_nome{nome}, m_cognome{cognome} {
        std::cout << "Costruzione Autore("
                  << nome << "," << cognome <<")\n";
    }
    std::string m_nome;
    std::string m_cognome;
};

struct Libro {
    Libro(const std::string& t,
          const std::string& n,
          const std::string& c)
        :  m_titolo{new Titolo{t}}, m_autore{n,c} {
        ++s_istanze;
        std::cout << "Costruzione Libro(" << t
                  << "," << n << "," << c <<")\n";
    }

    // Costruttore di copia
    Libro(const Libro& o)
        : m_titolo{new Titolo{*o.m_titolo}},
        m_autore{o.m_autore} {
        ++s_istanze;
        std::cout << "Costruisco una copia di Libro("
                  << m_titolo->m_t << ","
                  << m_autore.m_nome << ","
                  << m_autore.m_cognome << ")\n";
    }

    // Operatore di assegnamento di copia
    Libro& operator=(const Libro& o) {
        *m_titolo = *o.m_titolo;
        m_autore = o.m_autore;
        std::cout << "Operatore di assegnamento di copia di Libro("
                  << m_titolo->m_t << ","
                  << m_autore.m_nome << ","
                  << m_autore.m_cognome << ")\n";
        return *this;
    }

    // Distruttore
    ~Libro() {
        --s_istanze;
        std::cout << "Distruzione Libro("
                  << m_titolo->m_t << ","
                  << m_autore.m_nome << ","
                  << m_autore.m_cognome << ")\n";
        delete m_titolo;
    }

    static int getIstanze() {
        return s_istanze;
    }

private:
    Titolo *m_titolo;
    Autore m_autore;
    static int s_istanze;
};

// Per i campi static è necessario dichiarare
// una "variabile globale"
int Libro::s_istanze = 0;

void fun(Libro b) {
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
}

int main() {
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
    Libro l1{"Il nome della cosa", "Ugo", "Ugazzi"};
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
    fun(l1);
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
    Libro *l2{new Libro{"Manuale delle giovani marmotte", "Walt", "Disney"}};
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
    fun(*l2);
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
    l1 = *l2;
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
    delete l2;
    std::cout << "Istanze di libro: " << Libro::getIstanze() <<"\n";
}
