#ifndef POLINOMIO_LONG_INT_H_
#define POLINOMIO_LONG_INT_H_

typedef struct polinomio_ld Polinomio_ld;

Polinomio_ld *criaPolinomioLI(long int c, long int e);

Polinomio_ld *copiaPolinomioLI(Polinomio_ld *poli);

#endif