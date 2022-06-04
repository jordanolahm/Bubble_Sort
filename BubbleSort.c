#include <stdio.h>
#include "BubbleSort.h"


void BubbleSort(ListaDinamica* ptrLista)
{
    int i, j, k, aux;
    int ValorSaida1, ValorSaida2;

    for(i = ptrLista->qtdeElementos - 1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            ValorSaida1 = ConsultaPosicao(ptrLista, j);
            ValorSaida2 = ConsultaPosicao(ptrLista, j+1);

            if(ValorSaida1 > ValorSaida2)
            {
                aux = ValorSaida1;
                AlteraPosicao(ptrLista, j, ValorSaida2);
                AlteraPosicao(ptrLista, j+1, aux);
            }
        }
    }
}
