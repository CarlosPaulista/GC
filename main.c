#include <stdio.h>
#include <stdlib.h>


typedef struct referencias {
    void *valor;
    void *refs;
} referencias;

referencias *malloc2(int tamanho);

void atrib2(referencias **a, referencias **b);


int main() {
    int ExA = 5;
    int ExB = 10;
    printf("\n\n_______________SEM ATRIB2________________\n\n");
    printf("End ExA = %d  Valor= %d \n", &ExA, ExA);
    printf("End ExA = %d  Valor= %d ", &ExB, ExB);
    ExA = ExB;
    printf("\n\nExA = ExB\n\nEnd de ExA = %d  Valor  de ExA= %d\n", &ExA, ExA);
    printf("End de ExA = %d  Valor  de ExB= %d\n", &ExB, ExB);

    printf("\n____________________________________\n\n");

    printf("===============COM ATRIB2================\n\n");
    referencias *a = malloc2(sizeof(int));
    a->valor = 5;
    printf("End A= %d   Valor A= %d   Ref %d\n\n", a, a->valor, a->refs);

    referencias *b = malloc2(sizeof(int));
    b->valor = 10;
    printf("End B =  %d Valor B= %d Ref =  %d\n\n", b, b->valor, b->refs);

    printf("A = B\n\n");
    atrib2(&a, &b);

    printf("End A = %d Valor A= %d Ref = %d\n\n", a, a->valor, a->refs);
    printf("End B= %d Valor B= %d Ref = %d\n", b, b->valor, b->refs);
    printf("-------------------------\n\n");


    return 0;
}
