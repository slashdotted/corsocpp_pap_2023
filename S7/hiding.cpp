#include <iostream>
using namespace std;
class Base {
public:
    virtual void f(double x)
    {
        cout << "Base::f(double x)" << endl;
    }

    void f(bool x)
    {
        cout << "Base::f(bool x)" << endl;
    }

    void f() {
        cout << "Base::f()" << endl;
    }

    virtual void g() {
        cout << "Base::g()" << endl;
    }
};

class Derived1 : public Base {
public:
    // Queste 2 versioni di f nascondono quelle di Base

    void f()
    {
        cout << "Derived1::f()" << endl;
    }

    void f(int x)
    {
        cout << "Derived1::f(int x)" << endl;
    }
};

class Derived2 : public Base {
public:
    void f()
    {
        cout << "Derived2::f()" << endl;
    }

    void f(int x)
    {
        cout << "Derived2::f(int x)" << endl;
    }

    // Soluzione 1: ri-dichiaro il metodo della classe Base
    // ev. richiamando la sua implementazione
    void f(double x) {
        Base::f(x);
    }
};

class Derived3 : public Base {
public:
    using Base::f;

    void f()
    {
        cout << "Derived3::f()" << endl;
    }

    void f(int x)
    {
        cout << "Derived3::f(int x)" << endl;
    }

    void g() override {
        cout << "Derived3::g()" << endl;
    }
};

int main()
{
    {
        Derived1 e;
        e.f(3.2);
        e.f(3);
        e.f(true);
        e.g();
    }
    {
        Derived2 e;
        e.f(3.2);
        e.f(3);
        e.f(true);
        e.Base::f(true); // Soluzione 2: indico la versione di f da utilizzare
        e.g();
    }
    {
        Derived3 e;
        e.f(3.2);
        e.f(3);
        e.f(true);
        e.g();
        e.f();
        Base *b{&e};
        b->f();
        b->g();
    }
}
