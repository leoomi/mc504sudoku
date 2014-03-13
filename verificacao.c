#include "verificacao.h"
#include <stdio.h>
#include <stdlib.h>

void* threadVerificaLinha(void *v){
  char **matriz = (char**)v;

  int i, j;

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      printf("%d ", matriz[i][j]);
    }     
    printf("\n");
  } 
  
}
