#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomioLI.h"

struct polinomio_ld {
    int grau;
    long int *coef;
};

Polinomio_ld *criaPolinomioLI(int tamanho) {
    Polinomio_ld *poli = (Polinomio_ld*)malloc(sizeof(Polinomio_ld));
    if (poli == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }

    poli->coef = (long int*) malloc((tamanho+1) * sizeof(long int));
    if (poli->coef == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }

    poli->grau = tamanho;
    return poli;
}

Polinomio_ld *copiaPolinomioLI(Polinomio_ld *poli) {
    Polinomio_ld *copia = (Polinomio_ld*)malloc(sizeof(Polinomio_ld));
    if (poli == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }
    copia->coef = calloc(poli->grau, sizeof(long int));
    if (poli->coef == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }
    copia->grau = poli->grau;

    atribuiPolinomioLI(copia,poli);

    return copia;
}

void atribuiPolinomioLI(Polinomio_ld* poli1, Polinomio_ld* poli2) {
    if (poli1->grau == poli2->grau) {
        for (int i = 0; i < poli2->grau + 1; ++i) {
            poli1->coef[i] = poli2->coef[i];
        }
    } else { //Medida de segurança para evitar atribuição de polinômios com tamanhos diferentes
        poli1->grau = poli2->grau;
        poli1->coef = (long int*) realloc(poli1->coef,(poli2->grau + 1) * sizeof(long int));
        for (int i = 0; i < poli2->grau + 1; ++i) {
            poli1->coef[i] = poli2->coef[i];
        }
    }
}

void atribuiValoresLI(Polinomio_ld* poli, int n, int valor) {
    poli->coef[n] = valor;
}

void imprimePolinomioLI(Polinomio_ld* poli) {
    for (int i = 0; i <= poli->grau; i++) {
        printf("%ldx^%d",poli->coef[i],i);
        if (i < poli->grau) {
            if (poli->coef[i+1] >= 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

void destroiPolinomioLI(Polinomio_ld* poli) {
        free(poli->coef);
        free(poli);
}

int devolveGrauLI(Polinomio_ld* poli){
    return poli->grau;
}

void aumentaGrauLI(Polinomio_ld* poli, int aumento) {
    int temp = poli->grau;
    poli->coef = (long int*) realloc(poli->coef,(poli->grau + aumento + 1) * sizeof(long int));
    poli->grau += aumento;
    for (int i = temp + 1; i <= poli->grau; ++i) {
        poli->coef[i] = 0;
    }
}

void diminuiGrauLI(Polinomio_ld* poli, int diminui) {
    poli->coef = (long int*) realloc(poli->coef,(poli->grau - diminui + 1) * sizeof(long int));
    poli->grau -= diminui;
    for (int i = poli->grau; i >= 0; --i) {
        if (poli->coef[i] == 0) {
            poli->coef = (long int*) realloc(poli->coef,(poli->grau) * sizeof(long int));
            poli->grau -= 1;
        } else {
            break;
        }
    }
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
            if (abs(poli1->coef[i] - poli2->coef[i]) <= 0.0001) {
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