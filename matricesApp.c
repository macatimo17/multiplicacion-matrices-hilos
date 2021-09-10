#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "funcionmatrices.h"
#include "ctime.h"

#define SIZE_DATA (1024*1024*64*3)

static double MEM_CHUNK[SIZE_DATA];

//Estrategia declaración de todas las variables de forma global

int N;
int numThreads;
double *matrizA, *matrizB, *matrizC;

void * multiplicacionMatricesT(void *arg){

  int i, j, k; //contadores
  int idThreads; //identificador del threads
  int portion; //porción de la matriz A a enviar
  int inicioFila, finFila; //inicio y fin de la porción de la matriz A

  idThreads   = *((int *) (arg)); //se obtiene el identificador del hilo secuencialmente
  portion     = N/numThreads; //Porcion a calcular
  inicioFila  = idThreads*portion;
  finFila     = (idThreads+1)*portion; //identificador empiza en 0

  for(i = inicioFila; i<finFila; i++){
    for(j = 0; j<N; j++){
      double *pA, *pB,suma = 0.0;
      pA = matrizA+(i*N); //fila
      pB = matrizB+j;  //columna
      for(k =0; k<N; k++, pA++, pB+=N){
        suma += (*pA * *pB);
      }
      matrizC[i*N+j] = suma;
    }
  }
  return 0;
}



int main(int argc, char **argv) {

  int cT; //contador general de hilos
  pthread_t * hilos; //declarando apuntadores a hilos (posix)
  
  N = (int) atof(argv[1]);
  numThreads = (int) atof(argv[2]);
  
  matrizA = MEM_CHUNK;
  matrizB = matrizA + N*N;
  matrizC = matrizB + N*N;

  matrizInit(N, matrizA, matrizB, matrizC);

  sampleStart();
  
  //declaración de hilos y asignación de memoria
  hilos = (pthread_t *) malloc(numThreads*sizeof(pthread_t));
  //Se reparte el trabajo invocando cada hilo
  for(cT = 0; cT<numThreads; cT++){
    int *tID; //puntero identificado del hilo
    tID = (int *) malloc(sizeof(int));
    *tID = cT; //se apunta el puntero al contador general de hilos
    pthread_create(&hilos[cT], NULL, multiplicacionMatricesT, (void *) tID);
  }
  
  for(cT = 0; cT<numThreads; cT++){
    //espera a que todos los hilos terminen al tiempo (sincronización)
    pthread_join(hilos[cT], NULL);
  }

  sampleStop();
  printTime();

  return 0;
}
