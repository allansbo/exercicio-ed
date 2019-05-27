#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *arquivo = NULL;
  char palavra[20];

  printf("Informe o nome do arquivo: ");
  scanf("%s", &palavra);
  arquivo = fopen(palavra, "a");

  if (arquivo == NULL){
    printf("Erro na abertura do arquivo!\n");
  }else{
    printf("O arquivo foi aberto!\n");
  }
  return 0;
}
