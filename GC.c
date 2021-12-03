#include <stdlib.h>
#include <stdio.h>


typedef struct referencias {
    void *valor;
    void *refs;
} referencias;

referencias *malloc2(int tamanho);

void atrib2(referencias **a, referencias **b);


referencias *malloc2(int tamanho) {
    referencias *a = (referencias *) malloc(tamanho);
    a->refs = 1;
    return a;
}

void atrib2(referencias **a, referencias **b) {
    if (*b == NULL) {
        if ((*a)->refs == 1) {
            referencias *aux = *a;
            *a = NULL;
            aux->refs = aux->refs - 1;
            free(aux);


        } else {
            (*a)->refs = (*a)->refs- 1;
            *a = NULL;
        }
    }

    if ((*a)->refs == 1) {
        referencias *aux = *a;
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

