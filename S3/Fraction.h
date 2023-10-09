#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

// Posso dichiarare una classe anche utilizzando la parola
// chiave "class"
class Fraction {
    double valore; // Il livello di visibilità predefinito è private!
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int den);
    Fraction();
    /*explicit*/ Fraction(int num);
    void print() const;
    int getDenominator() const;
    int getNumerator() const;
    void setDenominator(int den);
    void setNumerator(int num);

    // Overloading degli operatori
    Fraction& operator += (const Fraction& f);
    Fraction& operator -= (const Fraction& f);

    Fraction operator - (const Fraction& f) const;

    // Operatore di conversione
    /*operator double () const {
        return (double) numerator / denominator;
    };*/
protected:
    // ..
};

std::ostream& operator<<(std::ostream& o, const Fraction& f);

#endif // FRAZIONE_H
