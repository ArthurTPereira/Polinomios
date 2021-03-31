#include <stdio.h>
#include <stdlib.h>
#include "polinomioD.h"
#include "polinomioLI.h"

int main() {

    Polinomio_D* p1 = criaPolinomioD(3);
    Polinomio_D* p2 = criaPolinomioD(3);

    atribuiValoresD(p1,2,4);
    atribuiValoresD(p2,2,8);

    imprimePolinomioD(p1);
    imprimePolinomioD(p2);

    destroiPolinomioD(p1);
    destroiPolinomioD(p2);
    return 0;
}