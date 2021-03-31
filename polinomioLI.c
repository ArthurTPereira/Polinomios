#include <stdio.h>
#include <stdlib.h>
#include "polinomioLI.h"

struct polinomio_ld {
    int grau;
    long int *coef;
};

Polinomio_ld *criaPolinomioLI(int tamanho) {
    Polinomio_ld *poli = (Polinomio_ld*)malloc(sizeof(Polinomio_ld));
    poli->coef = calloc(tamanho+1, sizeof(long int));
    poli->grau = tamanho;

    return poli;
}

Polinomio_ld *copiaPolinomioLI(Polinomio_ld *poli) {
    Polinomio_ld *copia = (Polinomio_ld*)malloc(sizeof(Polinomio_ld));
    copia->coef = calloc(poli->grau, sizeof(long int));
    copia->grau = poli->grau;

    //funcao pra atribuir valor

    return copia;
}

void atribuiPolinomioLI(Polinomio_ld* poli1, Polinomio_ld* poli2) {
    poli1->grau = poli2->grau;
    poli1->coef = poli2->coef;
}

void atribuiValoresLI(Polinomio_ld* poli, int n, int valor) {
    poli->coef[n] = valor;
}

void imprimePolinomioLI(Polinomio_ld* poli) {
    for (int i = 0; i <= poli->grau; i++) {
        printf("%lfx^%d",poli->coef[i],i);
        if (i < poli->grau) {
            if (poli->coef[i+1] >= 0) {
                printf(" + ");
            }
        }
    }
}

void destroiPolinomioLI(Polinomio_ld* poli) {
        free(poli->coef);
        free(poli);
}

int devolveGrauLI(Polinomio_ld* poli){
    return poli->grau;
}

void aumentaGrauLI(Polinomio_ld* poli, int aumento) {
    poli = realloc(poli,poli->grau + aumento);
    poli->grau += aumento;
}

void diminuiGrauLI(Polinomio_ld* poli, int aumento) {
    poli = realloc(poli,poli->grau - aumento);
    poli->grau -= aumento;
}

long int devolveCoeficienteLI(Polinomio_ld* poli, int posicao) {
    return poli->coef[posicao];
}

int verificaZerosLI(Polinomio_ld* poli) {
    int count = 0;
    for (int i = 0; i < poli->grau; i++) {
        if (poli->coef[i] >= -0.0001 && poli->coef[i] <= 0.0001) {
            count++;
        }
    }
    if (count == poli->grau) {
        return 1;
    } else {
        return 0;
    }
}

int verificaIgualdadeLI(Polinomio_ld* poli1, Polinomio_ld* poli2) {
    int count = 0;
    if (poli1->grau == poli2->grau) {


        for (int i = 0; i < poli1->grau; i++) {
            if (fabs(poli1->coef[i] - poli2->coef[i]) <= 0.0001) {
                count++;
            }
        }
    }
    
    if (count == poli1->grau) {
        return 1;
    } else {
        return 0;
    }
}