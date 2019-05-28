#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CIDADENOME 128
#define MAX 10

typedef char NOMECID;

typedef struct{
  NOMECID cidade;
}REGISTRO;

typedef struct aux{
  REGISTRO reg;
  struct aux* ant;
  struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
  PONT inicio;
}LISTA;

void inicializarLista(LISTA* l){
  l->inicio = NULL;
  printf("Lista inicializada\n\n");
}

int main() {
  LISTA* l = (LISTA*) malloc(sizeof(LISTA));
  REGISTRO reg;

  inicializarLista(l);
  printf("Informe a cidade: ");

  return 0;
}
