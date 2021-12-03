#include <stdlib.h>
#include <stdio.h>


typedef struct referencia {
    void *valor;
    void *refs;
} referencia;

referencia *malloc2(int tamanho);

void atrib2(referencia **a, referencia **b);


referencia *malloc2(int tamanho) {
    referencia *a = (referencia *) malloc(tamanho);
    a->refs = 1;
    return a;
}

void atrib2(referencia **a, referencia **b) {
    if (*b == NULL) {
        if ((*a)->refs == 1) {
            referencia *aux = *a;
            *a = NULL;
            aux->refs = aux->refs - 1;
            free(aux);


        } else {
            (*a)->refs = (*a)->refs- 1;
            *a = NULL;
        }
    }

    if ((*a)->refs == 1) {
        referencia *aux = *a;
        *a = *b;
        (*b)->refs =(*b)->refs + 1;
        aux->refs = aux->refs - 1;;
        free(aux);


    } else {
        (*a)->refs = (*a)->refs - 1;
        *a = *b;
        (*b)->refs = (*b)->refs + 1;

    }
}

