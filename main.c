#include <stdio.h>
#include <stdlib.h>
#include "polinomioD.h"
#include "polinomioLI.h"

int main() {

    Polinomio_D* p1 = criaPolinomioD(3);

    for (int i = 0; i <= 3; ++i) {
        atribuiValoresD(p1,i,i-1);
    }

    imprimePolinomioD(p1);

    destroiPolinomioD(p1);
    return 0;
}