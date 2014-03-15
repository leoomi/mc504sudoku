#include "dica.h"
#include <pthread.h>
#include <stdio.h>


pthread_t threads[3];

void* linhas(void *v){
    argumento *testeMatriz = (argumento*)v;
    int i,x,y;
    x = testeMatriz->x;
    y = testeMatriz->y;
  //checa linhas
     for(i = 0; i < 9; i++){
         if(testeMatriz->matriz[9*x + i].valor != 0){
         testeMatriz->matriz[9*x + y].dicas[ testeMatriz->matriz[9*x + i].valor - 1 ]++;
    }
  }
}

void* colunas(void *v){
    argumento *testeMatriz = (argumento*)v;
    int i,x,y;
    x = testeMatriz->x;
    y = testeMatriz->y;
    for(i = 0; i < 9; i++){
    if(testeMatriz->matriz[9*i+y].valor != 0){
      testeMatriz->matriz[9*x + y].dicas[ testeMatriz->matriz[9*i+y].valor - 1]++;
    }
  }
}

void* quadrados(void *v){
    argumento *testeMatriz = (argumento*)v;
    int i,j,x,y;
    x = testeMatriz->x;
    y = testeMatriz->y;
    
    for(i = (x/3)*3 ; i < (x/3)*3 + 3; i++){
    for(j = (y/3)*3 ; j < (y/3)*3 + 3; j++){
      if(testeMatriz->matriz[9*i + j].valor != 0){
	testeMatriz->matriz[9*x + y].dicas[ testeMatriz->matriz[9*i + j].valor - 1]++;
      }
    }
  }   
}


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
  
  argumento arg;
  arg.matriz = &matriz[0][0];
  arg.x = x;
  arg.y = y;
  
  pthread_create(&threads[0], NULL, linhas, (void *)&arg);
  pthread_create(&threads[1], NULL, colunas, (void *)&arg);
  pthread_create(&threads[2], NULL, quadrados, (void *)&arg);
  for(i = 0; i < 3; i++){
    pthread_join(threads[i], NULL);
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
