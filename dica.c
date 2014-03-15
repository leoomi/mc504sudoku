#include "dica.h"
#include <pthread.h>
#include <stdio.h>

void moduloDicas(){
  printf("Entre com o sudoku para completar dicas:\n");
  
  sudoku matriz[9][9];
  int i, j, k;

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      scanf("%i", &matriz[i][j].valor);
    }     
  }   

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      for(k = 0; k < 9; k++){
	matriz[i][j].dicas[k] = 0;
      }
    }     
  }
  
  preencheDicas(matriz);
  imprimeDicas(matriz);
}

void preencheDicas(sudoku matriz[][9]){
  int i, j;

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      if(matriz[i][j].valor == 0){
	checaDicasCelula(i , j, matriz );
      }
    }
  }
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
    for(j = (y/3)*3 ; j < (y/3)*3 + 3; j++){
      if(matriz[i][j].valor != 0){
	matriz[x][y].dicas[ matriz[i][j].valor - 1]++;
      }
    }
  }

}

void imprimeDicas(sudoku matriz[][9]){
  int i, j;

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      if(matriz[i][j].valor == 0){
	int k;
	printf("(");

	for(k = 0; k < 9; k++){
	  if(matriz[i][j].dicas[k] == 0){
	    printf("%d", k + 1);
	  }
	}
       
	printf(") ");
      }

      else{
	printf("%d ", matriz[i][j].valor);
      }
    }
    printf("\n");
  }
}
