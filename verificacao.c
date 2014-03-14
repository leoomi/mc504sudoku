#include "verificacao.h"
#include <stdio.h>
#include <stdlib.h>

void* threadVerificaLinhas(void *v){
  int *matriz = (int*)v;
  int numeros[9];
  int correto = 1;

  int i, j;

  for(i = 0; i < 9; i++){
    
    //zera vetor
    for(j = 0; j < 9; j++){
      numeros[j] = 0;
    }
    
    //conta quantas vezes cada numero aparece
    for(j = 0; j < 9; j++){
      numeros[matriz[i*9 + j] - 1]++;
    }
    
    //verifica se ha mais de um elemento
    for(j = 0; j < 9; j++){
      if(numeros[j] >= 2){
	correto = 0;
	printf("A linha %d contem %d ocorrencias do numero %d.\n", i+1, numeros[j], j+1);
      }
    }
  }
}

void* threadVerificaColunas(void *v){
  int *matriz = (int*)v;
  int numeros[9];
  int correto = 1;

  int i, j;

  for(i = 0; i < 9; i++){
    
    //zera vetor
    for(j = 0; j < 9; j++){
      numeros[j] = 0;
    }
    
    //conta quantas vezes cada numero aparece
    for(j = 0; j < 9; j++){
      numeros[matriz[i + j*9] - 1]++;
    }
    
    //verifica se ha mais de um elemento
    for(j = 0; j < 9; j++){
      if(numeros[j] >= 2){
	correto = 0;
	printf("A coluna %d contem %d ocorrencias do numero %d.\n", i+1, numeros[j], j+1);
      }
    }
  }
}

void* threadVerificaQuadrados(void *v){
  int *matriz = (int*)v;
  int numeros[9];
  int i, j, k, l;
  
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      
      for(k = 0; k < 9; k++){
	numeros[k] = 0;
      } 
      
      for(k = 0; k < 3; k++){
	for(l = 0; l < 3; l++){
	  numeros[matriz[(i*3 + k)* 9 + (j*3 + l)] - 1]++;
	}  
      }
      
      for(k = 0; k < 9; k++){
	if(numeros[k] >= 2){
	  printf("A quadrado (%d, %d) contem %d ocorrencias do numero %d.\n", i+1,j+1, numeros[k], k+1);
	}
      }
      
    }
  }
  
}
