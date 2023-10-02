#include "Fraction.h"
#include <iostream>

Fraction::Fraction(int num, int den)
    : numerator{num}, denominator{den == 0 ? 1 : den}  // init-list
{
    // l'oggetto Fraction è già stato inizializzato
}

Fraction::Fraction() : Fraction{0,1} {
}

Fraction::Fraction(int num) : Fraction{num,1} {
}

void Fraction::print() {
    std::cout << numerator << "/" << this->denominator << '\n';
}

int Fraction::getDenominator()
{
    return denominator;
}

int Fraction::getNumerator()
{
    return numerator;
}

void Fraction::setDenominator(int den) {
    if (den == 0) {
        denominator = 1;
    } else {
        denominator = den;
    }
}

void Fraction::setNumerator(int num) {
    numerator = num;
}

