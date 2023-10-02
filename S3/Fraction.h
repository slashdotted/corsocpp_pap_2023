#ifndef FRACTION_H
#define FRACTION_H

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
    Fraction(int num);
    void print();
    int getDenominator();
    int getNumerator();
    void setDenominator(int den);
    void setNumerator(int num);
protected:
    // ..
};

#endif // FRAZIONE_H
