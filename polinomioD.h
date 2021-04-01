#ifndef POLINOMIO_DOUBLE_H_
#define POLINOMIO_DOUBLE_H_

typedef struct polinomio_D Polinomio_D;

Polinomio_D* criaPolinomioD(int tamanho);

Polinomio_D* copiaPolinomioD(Polinomio_D* poli);

void atribuiPolinomioD(Polinomio_D* poli1, Polinomio_D* poli2);

int devolveGrauD(Polinomio_D* poli);

void aumentaGrauD(Polinomio_D* poli, int aumento);

void diminuiGrauD(Polinomio_D* poli, int diminui);

double devolveCoeficienteD(Polinomio_D* poli, int posicoo);

void atribuiValoresD(Polinomio_D* poli, int n, int valor);

int verificaZerosD(Polinomio_D* poli);

int verificaIgualdadeD(Polinomio_D* poli1, Polinomio_D* poli2);

void imprimePolinomioD(Polinomio_D* poli);

void destroiPolinomioD(Polinomio_D* poli);

#endif