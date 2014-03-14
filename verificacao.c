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
	printf("A linha %d contem %d ocorrencias do numero %d.", i+1, numeros[j], j+1);
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
	printf("A linha %d contem %d ocorrencias do numero %d.", i+1, numeros[j], j+1);
      }
    }
  }
}
