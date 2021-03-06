#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomioD.h"

struct polinomio_D {
    int grau;
    double* coef;
};

Polinomio_D* criaPolinomioD(int tamanho) {
    Polinomio_D* poli = (Polinomio_D*) malloc(sizeof(Polinomio_D));
    if (poli == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }

    poli->coef = (double*) malloc((tamanho + 1) * sizeof(double));
    if (poli->coef == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }

    poli->grau = tamanho;
    return poli;
}

Polinomio_D* copiaPolinomioD(Polinomio_D* poli) {
    Polinomio_D* copia = (Polinomio_D*) malloc(sizeof(Polinomio_D));
    if (poli == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }
    copia->coef = calloc(poli->grau,sizeof(double));
    if (poli->coef == NULL) {
        printf("Erro de alocação.\n");
        return NULL;
    }
    copia->grau = poli->grau;
    
    atribuiPolinomioD(copia,poli);

    return copia;
}

void atribuiPolinomioD(Polinomio_D* poli1, Polinomio_D* poli2) {
    if (poli1->grau == poli2->grau) {
        for (int i = 0; i < poli2->grau + 1; ++i) {
            poli1->coef[i] = poli2->coef[i];
        }
    } else { //Medida de segurança para evitar atribuição de polinômios com tamanhos diferentes
        poli1->grau = poli2->grau;
        poli1->coef = (double*) realloc(poli1->coef,(poli2->grau + 1) * sizeof(double));
        for (int i = 0; i < poli2->grau + 1; ++i) {
            poli1->coef[i] = poli2->coef[i];
        }
    }
}

int devolveGrauD(Polinomio_D* poli) {
    return poli->grau;
}

void aumentaGrauD(Polinomio_D* poli, int aumento) {
    int temp = poli->grau;
    poli->coef = (double*) realloc(poli->coef,(poli->grau + aumento + 1) * sizeof(double));
    poli->grau += aumento;
    for (int i = temp + 1; i <= poli->grau; ++i) {
        poli->coef[i] = 0;
    }
}

void diminuiGrauD(Polinomio_D* poli, int diminui) {
    poli->coef = (double*) realloc(poli->coef,(poli->grau - diminui + 1) * sizeof(double));
    poli->grau -= diminui;
    for (int i = poli->grau; i >= 0; --i) {
        if (poli->coef[i] == 0) {
            poli->coef = (double*) realloc(poli->coef,(poli->grau) * sizeof(double));
            poli->grau -= 1;
        } else {
            break;
        }
    }
}

double devolveCoeficienteD(Polinomio_D* poli, int posicao) {
    return poli->coef[posicao];
}

void atribuiValoresD(Polinomio_D* poli, int n, int valor) {
    poli->coef[n] = valor;
}

int verificaZerosD(Polinomio_D* poli) {
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

int verificaIgualdadeD(Polinomio_D* poli1, Polinomio_D* poli2) {
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

void imprimePolinomioD(Polinomio_D* poli) {
    for (int i = 0; i <= poli->grau; i++) {
        printf("%lfx^%d",poli->coef[i],i);
        if (i < poli->grau) {
            if (poli->coef[i+1] >= 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

void destroiPolinomioD(Polinomio_D* poli) {
        free(poli->coef);
        free(poli);
}
