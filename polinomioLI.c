#include <stdio.h>
#include <stdlib.h>
#include "polinomioLI.h"

struct polinomio_ld{
    long int coef;
    long int exp;
};

Polinomio_ld *criaPolinomioLI(long int c, long int e){
    Polinomio_ld *poli = (Polinomio_ld*)malloc(sizeof(Polinomio_ld));
    poli->coef = c;
    poli->exp = e;

    return poli;
}

Polinomio_ld *copiaPolinomioLI(Polinomio_ld *poli){
    Polinomio_ld *copia = criaPolinomioLI(poli->coef, poli->exp);

    return copia;
}

Polinomio_ld *atribuiPolinomioLI(Polinomio_ld *poli1, Polinomio_ld *poli2){
    poli1->coef = poli2->coef;
    poli1->exp = poli2->exp;

    return poli1;
}