#include <stdio.h>
#include "Data.h"

// Print vector     
void Vector_Print(int vector[n]){
    if (n <= 10){
        for (int i = 0; i < n; i++){
            printf("%d ",vector[i]);
        }
        printf(" ");
    }
}

// Print matrix     
void Matrix_Print(int matrix[n][n]) {
    if (n <= 10) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}
    
// Multiply matrices   
void Matrix_Mult(int MA[n][n], int MB[n][n], int result[n][n]) {
    int s;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            s=0;
            for (int j = 0; j < n; j++) {
                s += MA[k][j] * MB[j][i];
            }
            result[k][i] = s;
        }
    }
}


// Multiply vector and matrix   
void Vector_Matrix_Mult(int A[n],  int MA[n][n], int result[n]) {
    int s;
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            s += A[i] * MA[j][i];
        }
        result[i] = s;
    }
}
    
// Multiply integer and matrix   
void Matrix_Integer_Mult(int MA[n][n], int k, int result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = MA[i][j] * k;
        }
    }
}
    
// Multiply vectors     
int Vector_Mult(int A[n], int B[n]) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += A[i] * B[i];
    }
    return s;
} 
    
// Sum of vectors      
void Vector_Sum(int A[n], int B[n], int result[n]) {
    for (int i = 0; i < n; i++)
    {
        result[i] = A[i] + B[i];
    }
}
    
// Matrix sum   
void Matrix_Sum(int MA[n][n], int MB[n][n], int result[n][n]) {
       for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = MA[i][j] + MB[i][j];
        }
    }
}
    
// Sort matrix
void Matrix_Sort(int MA[n][n]) {
    int temp;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                if (MA[k][i] > MA[k][j]) {
                    temp = MA[k][j];
                    MA[k][j] = MA[k][i];
                    MA[k][i] = temp;
                }
            }
        }
    }
}

// Min element in matrix  
int Matrix_Min(int MA[n][n]) {
    int min = MA[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (min > MA[i][j]){
                min = MA[i][j];
            }
        }
    }
    return min;
}

// Max element in matrix    
int Matrix_Max(int MA[n][n]) {
    int max = MA[0][0];
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            if (max < MA[i][j]){
                max = MA[i][j];
            }
        }
    }
    return max;
}
    
// Vector filler 
void Vector_Filler(int A[n], int k) {
    for (int i = 0; i < n; i++)
    {
        A[i] = k;
    }
}

// Matrix filler    
void Matrix_Filler(int MA[n][n], int k) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            MA[i][j] = k;
        }
    }
}
    
// F1
int Func1(int A[n], int B[n], int C[n], int D[n], int MA[n][n], int ME[n][n]) {
    int S[n];
    int M[n];
    int V[n]; 
    int MX[n][n]; 
    int e;

    Vector_Sum(A, B, S);
    Matrix_Mult(MA, ME, MX);
    Vector_Matrix_Mult(D, MX, M);
    Vector_Sum(C, M, V);
    e = Vector_Mult(S, V);
    return e;
}

// F2
void Func2(int MF[n][n], int MG[n][n], int MH[n][n], int MK[n][n], int ML[n][n]) {
    int min;
    int max;
    int MI[n][n];
    int MX[n][n];
    int MR[n][n];
    min = Matrix_Min(MF);
    max = Matrix_Max(MH);
    Matrix_Integer_Mult(MG, min, MI);
    Matrix_Mult(MK, MF,MX);
    Matrix_Integer_Mult(MX, max, MR);
    Matrix_Sum(MI, MR, ML);
}
    
// F3
int Func3(int MS[n][n], int MR[n][n], int MT[n][n]) {
    int MX[n][n];
    int MN[n][n];
    int s;
    Matrix_Sort(MS);
    Matrix_Mult(MR, MT, MX);
    Matrix_Sum(MS, MX, MN);
    s = Matrix_Max(MN);
    return s;
}
