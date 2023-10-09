#include "Fraction.h"
#include <iostream>

Fraction operator+(Fraction a, const Fraction& b)
{
    return a += b;
}


/*Fraction operator+(const Fraction& a, const Fraction& b)
{
    Fraction c{a};
    c += b;
    return c;
}*/


void stampa(const Fraction& f) {
    std::cout << f.getNumerator() << "/" << f.getDenominator() << '\n';
}

int main() {
    Fraction f{3,4};
    Fraction g{3,4};
    f.print();

    f = Fraction{7};
    stampa(f);

    f += g;
    f.operator+=(g);


    std::cout << f;
    g = f + 5; // g = f.operator+(5); -> f.operator+(Fraction{5});
    g = 5 + f; // g = 5.operator+(f);
}
