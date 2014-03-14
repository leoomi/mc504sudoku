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
  
  checaDicasCelula(0, 0, matriz);
}

void checaDicasCelula(int x, int y, sudoku matriz[][9]){
  int i, j;

  //checa linhas
  for(i = 0; i < 9; i++){
    if(matriz[x][i].valor != 0){
      matriz[x][y].dicas[ matriz[x][i].valor - 1 ]++;
    }
  }

    //checa linhas
  for(i = 0; i < 9; i++){
    if(matriz[i][y].valor != 0){
      matriz[x][y].dicas[ matriz[i][y].valor - 1]++;
    }
  }

  for(i = (x/3)*3 ; i < (x/3)*3 + 3; i++){
    for(j = (y/3)*3 ; j < (y/3) + 3; j++){
      if(matriz[i][j].valor != 0){
	matriz[x][y].dicas[ matriz[i][j].valor - 1]++;
      }
    }
  }

}
