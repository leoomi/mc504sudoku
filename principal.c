#include <stdio.h>

int main(){
  int temp;
  int i, j;
  int matriz[9][9];

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      scanf("%d", &matriz[i][j]);
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

  threadVerificaQuadrados((void *)matriz);


  return 0;
}
