
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "Data.h"

/*-----------------------------------------

 --Done by Hrona Yurii_IO-83_8 variant
 --1.24  E = A+C*(MA*ME)+B
 --2.3   MF = MF*MG*k
 --3.13  T = S*(MO*MP)+SORT(S)*MR

-----------------------------------------*/

void* Calc1(void *arg){
    int A[n], B[n], C[n], D[n], MA[n][n], ME[n][n], e;

    printf("T1 - started\n");

    Vector_Filler(A, 1);
    Vector_Filler(B, 1);
    Vector_Filler(C, 1);
    Vector_Filler(D, 1);

    Matrix_Filler(MA, 1);
    Matrix_Filler(ME, 1);

    e = Func1(A, B, C, D, MA, ME);
    sleep(1);
    printf("\n%d", e);

    printf("\n\nT1 - finished\n\n");
    return NULL;
}

void* Calc2(void *arg){
    int MF[n][n], MG[n][n], MH[n][n], MK[n][n], Result[n][n];

    printf("T2 - started\n");

    Matrix_Filler(MF, 2);
    Matrix_Filler(MG, 2);
    Matrix_Filler(MH, 2);
    Matrix_Filler(MK, 2);
    
    Func2(MF, MG, MH, MK, Result);
    sleep(3);

    Matrix_Print(Result);

    printf("\nT2 - finished\n\n");
    return NULL;
  }

void* Calc3(void *arg){
    int MS[n][n], MR[n][n], MT[n][n], s;

    printf("T3 - started\n");

    Matrix_Filler(MS, 3);
    Matrix_Filler(MR, 3);
    Matrix_Filler(MT, 3);

    s = Func3(MS, MR, MT);
    sleep(5);
    printf("%d", s);

    printf("\n\nT3 - finished\n\n");   
    return NULL;
}


int main(){

pthread_t T1;
pthread_t T2;
pthread_t T3;

pthread_attr_t T1_attr;
pthread_attr_t T2_attr;
pthread_attr_t T3_attr;

pthread_attr_init (&T1_attr);
pthread_attr_init (&T2_attr);
pthread_attr_init (&T3_attr);

pthread_attr_setstacksize(&T1_attr, 8388608);
pthread_attr_setstacksize(&T2_attr, 8388608);
pthread_attr_setstacksize(&T3_attr, 8388608);

pthread_create(&T1, &T1_attr, Calc1, NULL);
pthread_create(&T2, &T2_attr, Calc2, NULL);
pthread_create(&T3, &T3_attr, Calc3, NULL);

pthread_join(T1, NULL);
pthread_join(T2, NULL);
pthread_join(T3, NULL);
}
