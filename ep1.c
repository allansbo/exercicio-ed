/*
  Este programa é a realização de uma atividade proposta pelo professor da matéria
  de Engenharia de Software do terceiro semestre do curso de Análise e Desenvolvimento de Sistemas
  da FATEC de Campinas. A premissa deste programa é armazenar o nome de rodovias e as cidades onde cada
  uma delas tem de atravessar.

  Desenvolvido por: Allan Silva Barroso de Oliveira, Felipe Toledo e Gabriel Campos.
*/
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define CID 128

typedef char NOMECIDADE;

typedef struct
{
    NOMECIDADE A[CID];
} REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux* ant;
    struct aux* prox;
} CIDADE;

typedef CIDADE* PONT;

typedef struct
{
    PONT inicio;
} LISTA;

void inicializarLista (LISTA* l)
{
    l->inicio = NULL;
}

void finalizarLista (LISTA* l)
{
    PONT end = l->inicio;
    while (end != NULL)
    {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

void exibirLista(LISTA* l)
{
    PONT end = l->inicio;
    printf("--- inicio da lista---\n\n");
    while(end != NULL)
    {
        printf("- %s\n", end->reg.A);
        end = end->prox;
    }
    printf("\n--- fim da lista ---\n");
}

int comparar(REGISTRO ch, PONT atual)
{
    return strcmp(atual->reg.A, ch.A);
}


PONT buscaSequencialExc(LISTA* l, REGISTRO ch, PONT* ant)
{
    *ant = NULL;
    PONT atual = l->inicio;
    int i;
    while (atual != NULL)
    {
        i = comparar(ch, atual->reg.A);
        if( i < 0){
            *ant = atual;
            atual = atual->prox;
        }else{
            break;
        }
    }
    if((atual != NULL) && (strcmp(ch.A, atual->reg.A) == 0))
        return atual;
    return NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg)
{
    PONT ant, i;
    i = buscaSequencialExc(l, reg, &ant);
    if(i != NULL)
        return false;
    i = (PONT) malloc(sizeof(CIDADE));
    i->reg = reg;
    if(ant == NULL)
    {
        i->prox = l->inicio;
        l->inicio = i;
    }
    else
    {
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

void menu()
{
    printf("+----------------     MENU     ----------------+\n");
    printf("|                                              |\n");
    printf("|    [ 1 ] Inserir Cidade                      |\n");
    printf("|    [ 2 ] Listar Rodovias p/ cidade           |\n");
    printf("|    [ 3 ] Cruzamento de Rodovias p/ cidade    |\n");
    printf("|    [ 4 ] Sair                                |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n");
}

void limpaTela()
{
    system("clear");
}

void perguntaVolta()
{
    printf("[ 0 ] Sair\n");
    printf("[ 1 ] Voltar\n");
}

int main(int argc, char const *argv[])
{
    LISTA* l = (LISTA*) malloc(sizeof(LISTA));
    REGISTRO reg;
    bool volta;
    int opcao=1, pergunta;
    PONT retorno;

    inicializarLista (l);

    while(true)
    {
        limpaTela();
        menu();
        do
        {
            scanf("%d",&opcao);
        }
        while(opcao<1 || opcao>4);

        if(opcao==4)
        {
            return 0;
        }

        do
        {
            switch(opcao)
            {
            case 1:
                do
                {
                    limpaTela();
                    printf("registro: ");
                    scanf("%s",reg.A);
                    printf("\n");
                    inserirElemListaOrd(l, reg);
                    perguntaVolta();
                    printf("[ 2 ] Novo elemento\n");
                    do
                    {
                        scanf("%d",&pergunta);
                    }
                    while(pergunta<1 || pergunta>2);
                }
                while(pergunta==2);
                break;
            case 2:
                limpaTela();
                exibirLista(l);
                perguntaVolta();
                scanf("%d",&pergunta);
                break;
            case 3:
                limpaTela();
                /*
                printf("elemento: ");
                scanf("%d",&busca);
                retorno = buscaSeqOrd(l, busca);
                if(retorno==NULL)
                {
                    printf("Nao existe na lista\n\n");
                }else{
                    printf("Elemento [ %d ] da lista\n\n", retorno+1);
                }*/
                perguntaVolta();
                scanf("%d",&pergunta);
                break;
            case 4:
                limpaTela();
                perguntaVolta();
                scanf("%d",&pergunta);
                break;
            }
            if(pergunta==0)
            {
                return 0;
            }
        }
        while(pergunta!=1);
    }

    finalizarLista(l);
    free(l);
    return 0;
}
