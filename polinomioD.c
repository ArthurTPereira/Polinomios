#include <stdio.h>
#include <stdlib.h>
#include "polinomioD.h"

struct polinomio_D {
    double coef;
    double exp;
};

Polinomio_D* criaPolinomioD(double c, double e) {
    Polinomio_D* poli = (Polinomio_D*) malloc(sizeof(Polinomio_D));
    poli->coef = c;
    poli->exp = e;
    return poli;
}

Polinomio_D* copiaPolinomioD(Polinomio_D* poli) {
    Polinomio_D* copia = criaPolinomioD(poli->coef,poli->exp);
    return copia;
}

Polinomio_D* atribuiPolinomioD(Polinomio_D *poli1, Polinomio_D *poli2) {
    poli1->coef = poli2->coef;
    poli1->exp = poli2->exp;

    return poli1;
}

void imprimePolinomioD(Polinomio_D* poli[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%lf(%lf^%d)", poli[i]->coef,poli[i]->exp,i); // CHECAR POSSIVEL ERRO NO PDF
        if (i < tamanho-1) {
            if (poli[i+1]->coef > 0) {
                printf("+");
            }
        }
    }
}