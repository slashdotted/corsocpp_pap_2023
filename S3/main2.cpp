#include "Fraction.h"
#include <iostream>

Fraction operator+(Fraction a, const Fraction& b)
{
    return a += b;
}

void stampa(const Fraction& f) {
    std::cout << f.getNumerator() << "/" << f.getDenominator() << '\n';
}

int main() {
    Fraction f{3,4};
    f.print();

    f = 7;
    stampa(f);
}
