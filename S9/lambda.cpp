#include <iostream>
#include <functional>

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

void bar(std::function<int(int,int)> fn) {
    fn(8,9);
}

int main() {
    Sommatore s{7};
    std::cout << s.somma(5,4) << '\n';
    std::cout << s(5,4) << '\n';
    foo(s);

    /*auto*/ std::function<int(int,int)> somma = [] (int a, int b) {
        return a+b;
    };

    std::cout << somma(5,4) << '\n';

    int base{3};
    int k{5};
    auto incrementa = [base,k] (int a) { return k + base + a; };
    // = tutto per valore
    auto incrementa2 = [=] (int a) { return k + base + a; };
    std::cout << incrementa(5) << '\n';
    base = 7;
    std::cout << incrementa(5) << '\n';
    auto incrementa3 = [base,&k] (int a) { return k + base + a; };
    std::cout << incrementa3(8) << '\n';
    k = 10;
    std::cout << incrementa3(5) << '\n';
    // & tutto per riferimento
    auto incrementa4 = [&] (int a) { return k + base + a; };
    // &,base tutto per riferimento, tranne base (per valore)
    auto incrementa5 = [&,base] (int a) { return k + base + a; };
    // =,&k tutto per valore, tranne k (per riferimento)
    auto incrementa6 = [=,&k] (int a) { return k + base + a; };
}
