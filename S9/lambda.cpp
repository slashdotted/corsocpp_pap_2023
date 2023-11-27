#include <iostream>


struct Sommatore {

    Sommatore(int c=0) : m_c{c} {}

    int somma(int x, int y) {
        m_c = m_c+x+y;
        return m_c;
    }

    int operator()(int x, int y) {
        m_c = m_c+x+y;
        return m_c;
    }

private:
    int m_c;
};

void foo(Sommatore& x) {
     std::cout << x(5,4) << '\n';
}

int main() {
    Sommatore s{7};
    std::cout << s.somma(5,4) << '\n';
    std::cout << s(5,4) << '\n';
    foo(s);

    auto somma = [] (int a, int b) {
        return a+b;
    };

    std::cout << somma(5,4) << '\n';
}
