#include <stdio.h>
#include <stdlib.h>
#include "BubbleSort.h"
#include "CalculaTempo.h"

int main()
{
    ListaDinamica *lista = CriaLista2(5);
    double tempo;

    Insere(lista, 5);
    Insere(lista, 4);
    Insere(lista, 3);
    Insere(lista, 2);
    Insere(lista, 1);

    int i;

    printf("\bLista original\n");
    for(i = 0; i < lista->qtdeElementos; i++)
        printf("%d, ", ConsultaPosicao(lista, i));

    printf("\n\nLista ordenada\n");

    BubbleSort(lista);

    tempo = CalculaTempo(&BubbleSort,lista);

    for(i = 0; i < lista->qtdeElementos; i++)
        printf("%d, ", ConsultaPosicao(lista, i));

    printf("\nTempo: %f ms\n", tempo);

    return 0;
}
