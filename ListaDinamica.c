#include <stdlib.h>
#include "ListaDinamica.h"

int Copia(int *Destino, int *Origem)
{
    *Destino = *Origem;

    return 1;
}

int Compara(int Elemento, int ChaveBusca)
{
    if(Elemento == ChaveBusca)
        return 0;

    return 1;
}

// implementa o processo geral de busca por um elemento
No* ConsultaLocal(ListaDinamica *ptrLista, int ptrChave)
{
    No *ptrNo = ptrLista->ptrInicio;

    // percorre vetor/lista de elementos
    while(ptrNo->ptrProx != NULL)
    {
        // invoca rotina por meio do ponteiro para funcao para compara elemento
        // com chave de busca
        if (Compara(ptrNo->ptrElemento, ptrChave) == 0)
            return ptrNo;

        ptrNo = ptrNo->ptrProx;
    }

    // nao encontrou elementos com chave de busca
    return NULL;
}
No* ConsultaLocalNo(No *ptrNo, int ptrChave)
{
    // percorre vetor/lista de elementos
    while(ptrNo->ptrProx != NULL)
    {
        // invoca rotina por meio do ponteiro para funcao para compara elemento
        // com chave de busca
        if (Compara(ptrNo->ptrElemento, ptrChave) == 0)
            return ptrNo;

        ptrNo = ptrNo->ptrProx;
    }

    // nao encontrou elementos com chave de busca
    return NULL;
}
No* ConsultaPosicaoLocal(ListaDinamica *ptrLista, int idxPosicao)
{
  	//testa se ah posicao eh valida
    if (idxPosicao < 0 || idxPosicao >= ptrLista->qtdeElementos)
        return 0;

  	No *ptrAux = ptrLista->ptrInicio;
  	while( idxPosicao )
    {
      ptrAux = ptrAux->ptrProx;
    	idxPosicao--;
    }

  	return ptrAux;
}
int ExcluiLocal(ListaDinamica *ptrLista, No *ptrNoAux)
{
    if( ptrNoAux == NULL )
    	return NULL;

    // guarda referencia para elemento excluido
    int ptrElementoAux = ptrNoAux->ptrElemento;

    //realiza ajustes dos ponteiros
  	if (ptrNoAux == ptrLista->ptrInicio)
			ptrLista->ptrInicio = ptrNoAux->ptrProx;
  	else
      ptrNoAux->ptrAnt->ptrProx = ptrNoAux->ptrProx;

  	if (ptrNoAux == ptrLista->ptrFim)
			ptrLista->ptrFim = ptrNoAux->ptrAnt;
  	else
      ptrNoAux->ptrProx->ptrAnt = ptrNoAux->ptrAnt;

    free( ptrNoAux );
    ptrLista->qtdeElementos--;
    return ptrElementoAux;
}
No* CriaNo(int _ptrElemento)
{
    No *ptrNovo = (No *) malloc(sizeof(No));
    if ( !ptrNovo )
        return NULL;

    ptrNovo->ptrAnt      = NULL;
    ptrNovo->ptrElemento = _ptrElemento;
    ptrNovo->ptrProx     = NULL;

    return ptrNovo;
}

void CriaLista(ListaDinamica *ptrLista, int _maxElementos)
{
    // inicializa valores da lista
    ptrLista->qtdeElementos = 0;
    ptrLista->maxElementos  = _maxElementos;

    ptrLista->ptrInicio = NULL;
    ptrLista->ptrFim    = NULL;
    ptrLista->ptrAtual  = NULL;
}

ListaDinamica* CriaLista2(int _maxElementos)
{
    // tenta criar a lista
    ListaDinamica *ptrLista = (ListaDinamica *) malloc(sizeof(ListaDinamica));

    // testa se a lista NAO foi criada
    if ( !ptrLista )
        return NULL;

    // inicializa valores da lista
    ptrLista->qtdeElementos = 0;
    ptrLista->maxElementos  = _maxElementos;

    ptrLista->ptrInicio = NULL;
    ptrLista->ptrFim    = NULL;
    ptrLista->ptrAtual  = NULL;

    // retorna lista construida
    return ptrLista;
}

int Insere(ListaDinamica *ptrLista, int ptrElemento)
{
    // verifica se ha espaco para o novo elemento
    if (ptrLista->maxElementos  != -1 &&
        ptrLista->qtdeElementos == ptrLista->maxElementos)
        return 0;

    // posiciona novo elemento na lista
    No *ptrNovo = CriaNo( ptrElemento );
    if ( !ptrNovo )
        return -1;

    if ( !ptrLista->qtdeElementos )
        ptrLista->ptrInicio = ptrNovo;
    else
        ptrLista->ptrFim->ptrProx = ptrNovo;

    ptrNovo->ptrAnt  = ptrLista->ptrFim;
    ptrLista->ptrFim = ptrNovo;

    ptrLista->qtdeElementos++;
    return 1;
}
int InserePosicao(ListaDinamica *ptrLista, int ptrElemento, int idxPosicao)
{
    // verifica se ha espaco para o novo elemento
    if (ptrLista->maxElementos  != -1 &&
        ptrLista->qtdeElementos == ptrLista->maxElementos)
        return 0;

    // verifica se a posicao eh valida
    if(idxPosicao < 0 || idxPosicao > ptrLista->qtdeElementos)
        return -1;

    // posiciona novo elemento na lista
    No *ptrNovo = CriaNo( ptrElemento );
    if ( !ptrNovo )
        return -2;

    // caminha ate idxPosicao
    No *ptrNo = ptrLista->ptrInicio;
    while( idxPosicao )
    {
        ptrNo = ptrNo->ptrProx;
        idxPosicao--;
    }

    // posiciona novo elemento
    if ( !ptrLista->qtdeElementos ) // lista vazia
    {
        ptrLista->ptrInicio = ptrNovo;
        ptrLista->ptrFim    = ptrNovo;
    }
    else
    if (ptrNo == ptrLista->ptrInicio)
    {
        ptrNovo->ptrProx = ptrNo;
        ptrNo->ptrAnt    = ptrNovo;

        ptrLista->ptrInicio = ptrNovo;
    }
    if ( !ptrNo ) // chama rotina que insere no fim
    {
        ptrNovo->ptrAnt           = ptrLista->ptrFim;
        ptrLista->ptrFim->ptrProx = ptrNovo;
        ptrLista->ptrFim          = ptrNovo;
    }
    else // meio da lista
    {
        ptrNo->ptrAnt->ptrProx = ptrNovo;
        ptrNovo->ptrAnt        = ptrNo->ptrAnt;

        ptrNovo->ptrProx = ptrNo;
        ptrNo->ptrAnt    = ptrNovo;
    }

    ptrLista->qtdeElementos++;
    return 1;
}
int Exclui(ListaDinamica *ptrLista, int ptrChave)
{
    return ExcluiLocal(ptrLista, ConsultaLocal(ptrLista, ptrChave));
}
int ExcluiPosicao(ListaDinamica *ptrLista, int idxPosicao)
{
    return ExcluiLocal(ptrLista, ConsultaPosicaoLocal(ptrLista, idxPosicao));
}
int Consulta(ListaDinamica *ptrLista, int ptrChave)
{
    // chama rotina anterior para percorrer lista e verificar
    // se elemento esta na lista
    No *ptrAux = ConsultaLocal(ptrLista, ptrChave);

    // verifica se encontrou elemento e copia para parametro de saida
    if ( ptrAux )
        return ptrAux->ptrElemento;

    return NULL;
}
int ConsultaPosicao(ListaDinamica *ptrLista, int idxPosicao)
{
    // localiza elemento
  	No *ptrAux = ConsultaPosicaoLocal(ptrLista, idxPosicao);

    if( ptrAux == NULL )
    	return NULL;

    return ptrAux->ptrElemento;
}
int Altera(ListaDinamica *ptrLista, int ptrChave, int ptrNovo)
{
    // chama rotina anterior para percorrer lista e verificar
    // se elemento esta na lista
    No *ptrAux = ConsultaLocal(ptrLista, ptrChave);

    // verifica se encontrou elemento e copia o novo
    if ( ptrAux )
        return Copia(&ptrAux->ptrElemento, &ptrNovo);

    return 0;
}
int AlteraPosicao(ListaDinamica *ptrLista, int idxPosicao, int ptrNovo)
{
    // localiza elemento
  	No *ptrAux = ConsultaPosicaoLocal(ptrLista, idxPosicao);

    if( ptrAux == NULL )
    	return 0;

  return Copia(&ptrAux->ptrElemento, &ptrNovo);
}
//Relatorio responsabilidade do sistema e nao da lista




int ConsultaAtual(ListaDinamica *ptrLista, void *ptrElementoSaida)
{
    if ( !ptrLista->ptrAtual )
        return 0;

    return Copia(&ptrElementoSaida, &(ptrLista->ptrAtual->ptrElemento));
}
int PosicionaInicio  (ListaDinamica *ptrLista)
{
    if ( !ptrLista->qtdeElementos )
        return 0;

    ptrLista->ptrAtual = ptrLista->ptrInicio;
    return 1;
}
int PosicionaFim(ListaDinamica *ptrLista)
{
    if ( !ptrLista->qtdeElementos )
        return 0;

    ptrLista->ptrAtual = ptrLista->ptrFim;
    return 1;
}
int PosicionaPosicao (ListaDinamica *ptrLista, int idxPosicao)
{
  	//testa se ah posicao eh valida
    if (idxPosicao < 0 || idxPosicao >= ptrLista->qtdeElementos)
        return 0;

  	ptrLista->ptrAtual = ptrLista->ptrInicio;
  	while( idxPosicao )
    {
      ptrLista->ptrAtual = ptrLista->ptrAtual->ptrProx;
    	idxPosicao--;
    }

  	return 1;
}
int PosicionaProximo (ListaDinamica *ptrLista)
{
    if ( !ptrLista->ptrAtual )
        return 0;

    ptrLista->ptrAtual = ptrLista->ptrAtual->ptrProx;
    return 1;
}
int PosicionaAnterior(ListaDinamica *ptrLista)
{
    if ( !ptrLista->ptrAtual )
        return 0;

    ptrLista->ptrAtual = ptrLista->ptrAtual->ptrAnt;
    return 1;
}
int EstaNoInicio(ListaDinamica *ptrLista)
{
    return ptrLista->ptrAtual == ptrLista->ptrInicio;
}
int EstaNoFim(ListaDinamica *ptrLista)
{
    return ptrLista->ptrAtual == ptrLista->ptrFim;
}
