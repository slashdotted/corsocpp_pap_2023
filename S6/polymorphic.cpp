#include <iostream>
using namespace std;

class Base
{
public:
    void bar() { cout << "\tBase::bar()" << endl; }
};

class Derived : public Base
{
public:
    virtual void bar() { cout << "\tDerived::bar()" << endl; }
};

class SottoDerived : public Derived
{
public:
    void bar() { cout << "\tSottoDerived::bar()" << endl; }
};

int main()
{
    SottoDerived sd;
    Base &bd{sd};
    Derived &dd{sd};
    bd.bar();
    dd.bar();
}
