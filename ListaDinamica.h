#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED

typedef struct No
{
    struct No *ptrAnt;
    int       ptrElemento;
    struct No *ptrProx;
}No;

typedef struct
{
    int qtdeElementos;
    int maxElementos;
    No  *ptrInicio,
        *ptrFim,
        *ptrAtual;
} ListaDinamica;

void CriaLista(ListaDinamica *ptrLista, int _maxElementos);
ListaDinamica* CriaLista2(int _maxElementos);

int Insere         (ListaDinamica *ptrLista, int ptrElemento);
int InserePosicao  (ListaDinamica *ptrLista, int ptrElemento, int idxPosicao);
int Exclui       (ListaDinamica *ptrLista, int ptrChave);
int ExcluiPosicao(ListaDinamica *ptrLista, int idxPosicao);
int Consulta       (ListaDinamica *ptrLista, int ptrChave);
int ConsultaPosicao(ListaDinamica *ptrLista, int idxPosicao);
int Altera         (ListaDinamica *ptrLista, int ptrChave, int ptrNovo);
int AlteraPosicao  (ListaDinamica *ptrLista, int idxPosicao, int ptrNovo);
//Relatorio responsabilidade do sistema e nao da lista

int ConsultaAtual    (ListaDinamica *ptrLista, void *ptrElementoSaida);
int PosicionaInicio  (ListaDinamica *ptrLista);
int PosicionaPosicao (ListaDinamica *ptrLista, int idxPosicao);
int PosicionaFim     (ListaDinamica *ptrLista);
int PosicionaProximo (ListaDinamica *ptrLista);
int PosicionaAnterior(ListaDinamica *ptrLista);
int EstaNoInicio     (ListaDinamica *ptrLista);
int EstaNoFim        (ListaDinamica *ptrLista);

#endif // LISTADINAMICA_H_INCLUDED
