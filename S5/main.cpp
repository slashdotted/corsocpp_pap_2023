#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <memory>

void esempio_vector() {
    std::vector<int> contenitore;
    // Aggiunta
    contenitore.push_back(1);
    contenitore.push_back(2);
    contenitore.push_back(3);
    contenitore.push_back(4);
    contenitore.push_back(5);
    contenitore.push_back(6);
    // Rimozione
    contenitore.erase(contenitore.begin());
    contenitore.erase(contenitore.begin() + 3);
    // Iterare sugli elementi
    for(auto& e : contenitore) {
        e *= 2;
        std::cout << e << '\n';
    }
    // Dimensione
    std::cout << contenitore.size() << '\n';
    // Iterazione con indice
    for(auto i{0}; i < contenitore.size(); ++i) {
        std::cout << contenitore[i] << '\n';
    }
    contenitore.at(3); // accesso "sicuro"

    std::vector<int> contenitore2 {1,2,3,4,5,6,7,8};
}

void esempio_list() {
    std::list<int> contenitore;
    // Aggiunta
    contenitore.push_back(1);
    contenitore.push_back(2);
    contenitore.push_back(3);
    contenitore.push_back(4);
    contenitore.push_back(5);
    contenitore.push_back(6);
    // Rimozione
    contenitore.erase(contenitore.begin());
    auto it{contenitore.begin()};
    std::advance(it, 3);
    contenitore.erase(it);
    // Iterare sugli elementi
    for(auto& e : contenitore) {
        e *= 2;
        std::cout << e << '\n';
    }
    // Dimensione
    std::cout << contenitore.size() << '\n';

    auto e{*it}; // accesso agli elementi
    std::cout << e << '\n';

    std::list<int> contenitore2 {1,2,3,4,5,6,7,8};
}

void esempio_map() {
    std::map<std::string,std::string> mappa;
    mappa["Corso"] = "Approfondimento Linguaggi";
    // Verifica se una chiave esiste:
    // SBAGLIATO:
    //if (mappa["Scuola"] != nullptr) {
    //    std::cout << "La chiave Scuola esiste\n";
    //}
    // GIUSTO:
    if (mappa.count("Scuola") == 1){
        std::cout << "La chiave Scuola esiste\n";
    }
    // Rimozione
    mappa.erase("Scuola");
}

void esempio1_smartpointer() {
    std::vector<int*> v;
    int *a{new int{56}};

    v.push_back(a);
    v.push_back(new int{9});

    for(auto& p : v) {
        delete p;
    }

    v.clear();

    //delete a;
}

struct Foo {
    Foo(std::string nome) : m_nome{nome} {std::cout << "Costruisco Foo " << m_nome <<"\n";}
    ~Foo() {std::cout << "Distruggo Foo " << m_nome << "\n";}

private:
    std::string m_nome;
};

struct MyUniqueFoo {
    MyUniqueFoo(Foo* p) : ptr{p} {}
    ~MyUniqueFoo() {
        delete ptr;
    }

    Foo& operator*() {
        return *ptr;
    }

    Foo* get() {
        return ptr;
    }

    void release() {
        ptr = nullptr;
    }
private:
    MyUniqueFoo(const MyUniqueFoo&) {}
    MyUniqueFoo& operator=(const MyUniqueFoo&) { return *this; }
    Foo* ptr;
};


struct MySharedFoo {
    MySharedFoo(Foo* p) : ptr{p},  counter{new int{1}} {}

    MySharedFoo(const MySharedFoo& o) : ptr{o.ptr}, counter{o.counter} {
        ++(*counter);
    }

    MySharedFoo& operator=(const MySharedFoo& o) {
        decrement();
        ptr = o.ptr;
        counter = o.counter;
        ++(*counter);
        return *this;
    }


    ~MySharedFoo() {
        decrement();
    }

    Foo& operator*() const{
        return *ptr;
    }

    Foo* get() const {
        return ptr;
    }

    int use_count() const  {
        return *counter;
    }

private:
    void decrement() {
        --(*counter);
        if (*counter == 0) {
            delete ptr;
            delete counter;
        }
    }

    Foo* ptr;
    int* counter;
};

void fun(std::unique_ptr<Foo> x) {

}

void fun(MyUniqueFoo x) {

}

void fun2(const MyUniqueFoo& x) {

}

void riempi_vector(std::vector<std::unique_ptr<Foo>>& v) {
    std::unique_ptr<Foo> p4{new Foo{"p4"}};
    v.push_back(std::move(p4));
    std::cout << "Fine di riempi_vector\n";
}

void esempio_unique_ptr() {
    std::unique_ptr<double> p{new double{3.14}};
    std::unique_ptr<Foo> p2{new Foo{"p2"}};

    MyUniqueFoo p3{new Foo{"p3"}};

    //fun(p2);
    //fun(p3);

    fun2(p3);

    std::vector<std::unique_ptr<Foo>> v;
    v.push_back(std::move(p2)); // trasferisco l'ownership di p2
    riempi_vector(v);

    double z{*p}; // dereferenziazione
    double *z1{p.get()};
    Foo& z2{*p3};

    auto p6{std::make_unique<Foo>("p6")};
    std::cout << "Fine di esempio_unique_ptr\n";
}

void fun(std::shared_ptr<Foo> p) {
    std::cout << "Numero rif: " << p.use_count() << '\n';
}

void esempio_shared_ptr() {
    std::shared_ptr<double> p{new double{3.14}};
    std::shared_ptr<Foo> p5{new Foo{"p5"}};
    auto p6{std::make_shared<Foo>("p6")};
    std::cout << "Numero rif: " << p.use_count() << '\n';
    fun(p6);
    std::cout << "Numero rif: " << p.use_count() << '\n';
    Foo& z{*p6};

    std::vector<std::shared_ptr<Foo>> v;
    v.push_back(p6);
}

// Video su noexcept: https://www.youtube.com/watch?v=AG_63_edgUg
void esempio_exceptions() noexcept {
    try {
        Foo s{"Computer"};
        //auto x{new Foo{"Casa"}};
        auto x{std::make_unique<Foo>("Casa")};
        throw "Houston abbiamo un problema";
        //delete x;
    } catch(const char* e) {
        std::cout << "Eccezione: " << e << '\n';
        //throw; // Rilancio eccezione
    } catch(int e) {
        std::cout << "Eccezione: " << e << '\n';
    } catch(...) { // Tutti gli altri tipi
        std::cout << "Eccezione: " << '\n';
        throw; // Rilancio eccezione
    }

    try {
        throw Foo{"Help!"};
    } catch(const char* e) {
        std::cout << "Eccezione: " << e << '\n';
    } catch(int e) {
        std::cout << "Eccezione: " << e << '\n';
    } catch(...) { // Tutti gli altri tipi
        std::cout << "Eccezione di altro tipo: " << '\n';
    }
}

void fun(MySharedFoo k) {
    std::cout << "In fun: counter = " << k.use_count() << '\n';
}

void esempio_mysharedptr() {
    MySharedFoo p{new Foo("Aldo")};
    MySharedFoo p2{new Foo{"Giovanni"}};
    std::cout << "Before fun: counter = " << p.use_count() << '\n';
    fun(p);
    std::cout << "After fun: counter = " << p.use_count() << '\n';
    p2 = p;
    std::cout << "After assign: counter = " << p.use_count() << '\n';
}

int main() {
    esempio_vector();
    esempio_list();
    esempio_map();
    esempio1_smartpointer();
    esempio_unique_ptr();
    esempio_shared_ptr();
    esempio_exceptions();
    esempio_mysharedptr();
}
