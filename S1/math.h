#ifndef MATH_H
#define MATH_H

// I namespace vanno indicati (se necessario) sia nel .h che nel .cpp
// I namespace possono essere anche gerarchici
namespace math {
namespace arithmetics {
// la funzione seguente può essere richiamata come math::arithmetics::somma
int somma(int a, int b=0);
}
}

#endif // MATH_H
