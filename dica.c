#include "dica.h"
#include <pthread.h>
#include <stdio.h>

void moduloDicas(){
  printf("Entre com o sudoku para completar dicas:\n");
  
  sudoku matriz[9][9];
  int i, j;

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      scanf("%i", &matriz[i][j].valor);
    }     
  }   
  
}

void checaDicasCelula(int x, int y, sudoku matriz[][9]){
  int i, j;

  //checa linhas
  for(i = 0; i < 9; i++){
    if(matriz[x][i] != 0){
      matriz[x][y].dicas[i - 1]++;
    }
  }

    //checa linhas
  for(i = 0; i < 9; i++){
    if(matriz[i][y] != 0){
      matriz[x][y].dicas[i - 1]++;
    }
  }

  for(){
    
  }
}
