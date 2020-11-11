#include <stdio.h>
#define n 3

void Vector_Print(int vector[n]);
void Matrix_Print(int matrix[n][n]);
void Matrix_Mult(int MA[n][n], int MB[n][n], int result[n][n]);
void Vector_Matrix_Mult(int A[n],  int MA[n][n], int result[n]);
void Matrix_Integer_Mult(int MA[n][n], int k, int result[n][n]);
int Vector_Mult(int A[n], int B[n]);
void Vector_Sum(int A[n], int B[n], int result[n]);
void Matrix_Sum(int MA[n][n], int MB[n][n], int result[n][n]);
void Matrix_Sort(int MA[n][n]);

int Matrix_Min(int MA[n][n]);
int Matrix_Max(int MA[n][n]);

void Vector_Filler(int A[n], int k);
void Matrix_Filler(int matrix[n][n], int k);

int Func1(int A[n], int B[n], int C[n], int D[n], int MA[n][n], int ME[n][n]);
void Func2(int MF[n][n], int MG[n][n], int MH[n][n], int MK[n][n], int ML[n][n]);
int Func3(int MS[n][n], int MR[n][n], int MT[n][n]);

