#include <stdio.h>
#include <stdlib.h>
#include "polinomioD.h"
#include "polinomioLI.h"

#define TAM 3

int main() {

    Polinomio_D* vet[TAM];
    double c,e;
    for (int i = 0; i < TAM; i++) {
        scanf("%lf %lf",&c,&e);
        vet[i] = criaPolinomioD(c,e);
    }
    imprimePolinomioD(vet,TAM);

    for (int j = 0; j < TAM; j++) {
        free(vet[j]);
    }

    return 0;
}