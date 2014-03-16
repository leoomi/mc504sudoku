#include "completar.h"
#include <pthread.h>
#include <stdio.h>
#define FALSE 0
#define TRUE 1

int verificaLinhas(int matriz[][9]){

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
    if(matriz[i][j]>0)
      numeros[matriz[i][j] - 1]++;
    }

    //verifica se ha mais de um elemento
    for(j = 0; j < 9; j++){
      if(numeros[j] >= 2){
        return FALSE;
      }
    }
    }
    return TRUE;
}

int verificaColunas(int matriz[][9]){
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
      if(matriz[j][i]>0){
      numeros[matriz[j][i] - 1]++;
      }
    }
    
    //verifica se ha mais de um elemento
    for(j = 0; j < 9; j++){
      if(numeros[j] >= 2){
	return FALSE;
      }
    }
    
  }
  return TRUE;
 }
 
int verificaQuadrados(int matriz[][9]){
  int numeros[9];
  int i, j, k, l;
  
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      
      for(k = 0; k < 9; k++){
	numeros[k] = 0;
      } 
      
      for(k = 0; k < 3; k++){
	for(l = 0; l < 3; l++){
	  if(matriz[(i*3 + k)][(j*3 + l)]>0)
	  numeros[matriz[(i*3 + k)][(j*3 + l)] - 1]++;
	}  
      }
      
      for(k = 0; k < 9; k++){
	if(numeros[k] >= 2){
	  return FALSE;
	}
      }
      
    }
  }
  
  return TRUE;
}

int completa(int  matriz[][9],int x, int y,int inicio, int fim){

   int retorno,i,j;
    
   if(x<9 && y<9)
   {
        if(matriz[x][y] != 0){
            if(y+1<9)
                return completa(matriz,x,y+1,0,9);
            else if (x+1 < 9)
                return completa(matriz,x+1,0,0,9);
            else return TRUE;
        }
        else{
            for(i=inicio; i<fim; i++)
            {
                matriz[x][y] = i+1;

                if(verificaQuadrados(matriz) == FALSE || verificaLinhas(matriz) == FALSE || verificaColunas(matriz) == FALSE){
                matriz[x][y] = 0;
                //return FALSE;
                }
                else{
                if(y+1<9){
                    if(completa(matriz,x,y+1,0,9))
                    return TRUE;
                    else matriz[x][y] = 0;
                }
                
                else if(x+1<9){
                    if(completa(matriz,x+1,0,0,9))
                    return TRUE;
                    else matriz[x][y]=0;
                }
                else return TRUE;
            }
          }
        }
        return FALSE;
   }
   else return TRUE;
}

  argumentos arg[9];

  void* thread0(void *v){
    argumentos *argument = (argumentos*)v;
    if(completa(argument[0].matriz,argument[0].x,argument[0].y,argument[0].inicio,argument[0].fim))
      argument[0].retorno = TRUE;
    else
      argument[0].retorno = FALSE;

  }


int moduloSolucao(){
  printf("Entre com o sudoku para solucao:\n");
  

  int i, j,k;



  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      scanf("%d", &arg[0].matriz[i][j]);
      for(k=0;k<9;k++){
      arg[k].matriz[i][j]=arg[0].matriz[i][j];
    }
    }     
  }
  int xInicio,yInicio,flag;
  flag =0;

  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
        if(arg[0].matriz[i][j] ==0 ){
          xInicio = i;
          yInicio = j;
          flag = 1;
        }
        break;
      }
      if(flag)
        break;
  }
  for(i=0;i<9;i++){
    arg[i].x = xInicio;
    arg[i].y = yInicio;
    arg[i].inicio = i;
    arg[i].fim = i+1;
  }

  
  pthread_t threads[9];
  
  pthread_create(&threads[0], NULL, thread0, &arg[0]);
  pthread_create(&threads[1], NULL, thread0, &arg[1]);
  pthread_create(&threads[2], NULL, thread0, &arg[2]);
  pthread_create(&threads[3], NULL, thread0, &arg[3]);
  pthread_create(&threads[4], NULL, thread0, &arg[4]);
  pthread_create(&threads[5], NULL, thread0, &arg[5]);
  pthread_create(&threads[6], NULL, thread0, &arg[6]);
  pthread_create(&threads[7], NULL, thread0, &arg[7]);
  pthread_create(&threads[8], NULL, thread0, &arg[8]);

    for(i = 0; i < 9; i++){
    pthread_join(threads[i], NULL);
  }

   //completa(matriz,0,0,0,9);

   printf("\n");
   for(k=0;k<9;k++){
   if((arg[k].retorno)){ //verifica se a thread conseguiu solucionar o sudoku
   for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      printf("%d ", arg[k].matriz[i][j]);
      if(j == 8)
      printf("\n");
    }     
  }
}
}

   return 0;
   
}  
