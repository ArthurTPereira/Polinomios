#ifndef POLINOMIO_DOUBLE_H_
#define POLINOMIO_DOUBLE_H_

typedef struct polinomio_D Polinomio_D;

Polinomio_D* criaPolinomioD(double c, double e);

Polinomio_D* copiaPolinomioD(Polinomio_D* poli);

Polinomio_D* atribuiPolinomioD(Polinomio_D *poli1, Polinomio_D *poli2);

void imprimePolinomioD(Polinomio_D* poli[], int tamanho);

#endif