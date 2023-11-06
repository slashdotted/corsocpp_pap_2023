#include <iostream>
using namespace std;

class Base {
public:
    virtual void f(double x)
    {
        cout << "Base::f(double x)" << endl;
    }
};

class Derived : public Base {
public:
    void f(double x) override
    {
        cout << "Derived::f(double x)" << endl;
    }
};


int main()
{
    Derived e;
    e.f(3.2);
    e.f(3);
}
