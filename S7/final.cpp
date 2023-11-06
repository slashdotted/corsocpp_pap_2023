class Base final
{
};

// Error
/*class Derived : public Base
{
};*/

class Base2
{
public:
    virtual void f() const {}
};

class Derived2 : public Base2
{
public:
    void f() const final override {}
};

class Derived3 : public Derived2
{
public:
    //void f() const override {}
};

int main() {
}
