#include <stdio.h>
#include "funcionmatrices.h"

void matrizInit(int N, double *matrizA, double *matrizB, double *matrizC) {
  int i,j;
  for(i = 0; i<N; i++){
    for(j=0; j<N; j++){
      matrizA[j+i*N]= 2.0*(i+j);
      matrizB[j+i*N]= 3.2*(i+j);
      matrizC[j+i*N]= 1.0*(i+j);
    }
  }
}

void multiplicacionMatrices(int N, double *matrizA, double *matrizB, double *matrizC) {
  int i;
  int j;
  int k;
  for(i = 0; i<N; i++){
    for(j = 0; j<N; j++){
      double *pA, *pB,suma = 0.0;
      pA = matrizA+(i*N);
      pB = matrizB+j;
      for(k =0; k<N; k++, pA++, pB+=N){
        suma += (*pA * *pB);
      }
      matrizC[i*N+j] = suma;
    }
  }
}

void imprimirMatriz(int N, double *matriz) {
  int i;
  int j;
  for(i = 0; i<N; i++){
    for(j = 0; j<N; j++){
      printf("%f \t ", matriz[j+i*N]);
    }
    printf("\n");
  }
}

