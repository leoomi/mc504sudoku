#include <stdio.h>

int main(){
  
  int i, j;
  char matriz[9][9];

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      scanf("%c", &matriz[i][j]);
    }     
  }   
  
  /*
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      printf("%d ", matriz[i][j]);
    }     
    printf("\n");
  } 
  */

  threadVerificaLinha((void *)matriz
);

  return 0;
}
