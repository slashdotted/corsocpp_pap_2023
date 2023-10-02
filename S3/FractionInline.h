#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class FractionInline {
    double valore; // private!
private:
    int numerator;
    int denominator;
public:
    // definizione inline
    FractionInline(int num, int den) {
        if (den == 0) {
            denominator = 1;
        } else {
            denominator = den;
        }
        numerator = num;
    }
    // definizione inline
    void print() {
        std::cout << numerator << "/" << this->denominator << '\n';
    }

    int getNumerator() {
        return numerator;
    }
protected:
    // ..
};

#endif // FRAZIONE_H
