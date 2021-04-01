#ifndef POLINOMIO_LONG_INT_H_
#define POLINOMIO_LONG_INT_H_

typedef struct polinomio_ld Polinomio_ld;

Polinomio_ld *criaPolinomioLI(int tamanho);

Polinomio_ld *copiaPolinomioLI(Polinomio_ld *poli);

void atribuiPolinomioLI(Polinomio_ld *poli1, Polinomio_ld *poli2);

void atribuiValoresLI(Polinomio_ld* poli, int n, int valor);

void imprimePolinomioLI(Polinomio_ld* poli);

void destroiPolinomioLI(Polinomio_ld* poli);

int devolveGrauLI(Polinomio_ld* poli);

void aumentaGrauLI(Polinomio_ld* poli, int aumento);

void diminuiGrauLI(Polinomio_ld* poli, int aumento);

long int devolveCoeficienteLI(Polinomio_ld* poli, int posicao);

int verificaZerosLI(Polinomio_ld* poli);

int verificaIgualdadeLI(Polinomio_ld* poli1, Polinomio_ld* poli2);

#endif