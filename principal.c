#include <stdio.h>
#include "verificacao.h"
#include "dica.h"

int main(){
  /*
  int temp;
  int i, j;
  int matriz[9][9];

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      scanf("%d", &matriz[i][j]);
    }     
  }   
  
  
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      printf("%d ", matriz[i][j]);
    }     
    printf("\n");
  } 
  */

  //threadVerificaQuadrados((void *)matriz);
  int escolha = 0;

  printf("Digite sua escolha:\n1. Verificacao\n2. Modo dica\n3. Modo de resolucao\n0. Sair\n");
  scanf("%d", &escolha);
  
  if(escolha == 1)
    moduloVerificacao();
  else if(escolha == 2)
    moduloDicas();
  return 0;
}
