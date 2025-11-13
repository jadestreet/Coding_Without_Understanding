#include <stdio.h>
#include <stdlib.h>
int** make2DArray(int n, int m);
void free2DArray(int **, int n);
void fulfil2DArray(int**, int n, int m);
void print2DArray(int**ptr, int rowNum, int colNum);
void matrixSum(int **result, int **A, int **B, int rowNum, int colNum);
void matrixMulti(int **result, int **A,int **B,int rowNumOfA,int colNumOfA,int rowNumOfB,int colNumOfB);
void matrixTranspose(int **matrixA_T, int **matrixA, int rowNum, int colNum);
int main(void){
    int **test1A , **test1B, **test1Result;
    test1A = make2DArray(1, 1);
    test1B = make2DArray(1, 1);
    test1Result = make2DArray(1, 1);
    fulfil2DArray(test1A, 1, 1);
    fulfil2DArray(test1B, 1, 1);
    fulfil2DArray(test1Result, 1, 1);
    matrixSum(test1Result, test1A, test1B, 1, 1);
    print2DArray(test1Result, 1, 1);
    puts("--------");
    test1A[0][0] = -1;
    matrixSum(test1Result, test1A, test1B, 1, 1);
    print2DArray(test1Result, 1, 1);
    puts("--------");
    free(test1A);
    free(test1B);
    free(test1Result);
    int **test2A , **test2B, **test2Result;
    test2A = make2DArray(1, 2);
    test2B = make2DArray(1, 2);
    test2Result = make2DArray(1, 2);
    fulfil2DArray(test2A, 1, 2);
    fulfil2DArray(test2B, 1, 2);
    fulfil2DArray(test2Result, 1, 2);
    matrixSum(test2Result, test2A, test2B, 1, 2);
    print2DArray(test2Result, 1, 2);
    puts("--------");
    free(test2A);
    free(test2B);
    free(test2Result);
    int **test3A , **test3B, **test3Result;
    test3A = make2DArray(2, 1);
    test3B = make2DArray(2, 1);
    test3Result = make2DArray(2, 1);
    fulfil2DArray(test3A, 2, 1);
    fulfil2DArray(test3B, 2, 1);
    fulfil2DArray(test3Result, 2, 1);
    matrixSum(test3Result, test3A, test3B, 2, 1);
    print2DArray(test3Result, 2, 1);
    puts("--------");
    free(test3A);
    free(test3B);
    free(test3Result);
    test1A = make2DArray(1, 1);
    test1B = make2DArray(1, 1);
    test1Result = make2DArray(1, 1);
    fulfil2DArray(test1A, 1, 1);
    fulfil2DArray(test1B, 1, 1);
    fulfil2DArray(test1Result, 1, 1);
    matrixMulti(test1Result, test1A, test1B, 1, 1, 1, 1);
    print2DArray(test1Result, 1, 1);
    puts("--------");
    test1A[0][0] = -1;
    matrixMulti(test1Result, test1A, test1B, 1, 1, 1, 1);
    print2DArray(test1Result, 1, 1);
    puts("--------");
    free(test1A);
    free(test1B);
    free(test1Result);
    test1A = make2DArray(1, 1);
    test1B = make2DArray(1, 1);
    test1Result = make2DArray(1, 3);
    fulfil2DArray(test1A, 1, 1);
    fulfil2DArray(test1B, 1, 3);
    fulfil2DArray(test1Result, 1, 3);
    matrixMulti(test1Result, test1A, test1B, 1, 1, 1, 3);
    print2DArray(test1Result, 1, 3);
    puts("--------");
    test1A[0][0] = -1;
    matrixMulti(test1Result, test1A, test1B, 1, 1, 1, 3);
    print2DArray(test1Result, 1, 3);
    puts("--------");
    free(test1A);
    free(test1B);
    free(test1Result);
    test1A = make2DArray(3, 1);
    test1B = make2DArray(1, 1);
    test1Result = make2DArray(3, 1);
    fulfil2DArray(test1A, 3, 1);
    fulfil2DArray(test1B, 1, 1);
    fulfil2DArray(test1Result, 3, 1);
    matrixMulti(test1Result, test1A, test1B, 3, 1, 1, 1);
    print2DArray(test1Result, 3, 1);
    puts("--------");
    test1A[0][0] = -1;
    matrixMulti(test1Result, test1A, test1B, 3, 1, 1, 1);
    print2DArray(test1Result, 3, 1);
    puts("--------");
    free(test1A);
    free(test1B);
    free(test1Result);
    int **matrix ,**matrix_T;
    matrix = make2DArray(1, 1);
    matrix_T = make2DArray(1, 1);
    fulfil2DArray(matrix, 1, 1);
    fulfil2DArray(matrix_T, 1, 1);
    matrixTranspose(matrix_T, matrix, 1, 1);
    print2DArray(matrix_T, 1, 1);
    puts("--------");
    free(matrix);
    free(matrix_T);
    matrix = make2DArray(2, 2);
    matrix_T = make2DArray(2, 2);
    fulfil2DArray(matrix, 2, 2);
    fulfil2DArray(matrix_T, 2, 2);
    matrixTranspose(matrix_T, matrix, 2, 2);
    print2DArray(matrix_T, 2, 2);
    puts("--------");
    free(matrix);
    free(matrix_T);
    matrix = make2DArray(3, 5);
    matrix_T = make2DArray(5, 3);
    fulfil2DArray(matrix, 3, 5);
    fulfil2DArray(matrix_T, 5, 3);
    matrixTranspose(matrix_T, matrix, 3, 5);
    print2DArray(matrix_T, 5, 3);
    puts("--------");
    free(matrix);
    free(matrix_T);
    return 0;
}
void matrixSum(int **result, int **A, int **B, int rowNum, int colNum){
    int i = 0, j = 0;
    for(i = 0; i < rowNum ; i++ ){
        for(j = 0; j < colNum ; j++){
                result[i][j]= A[i][j] + B[i][j];
        }
    }
}
void matrixMulti(int **result, int **A,int **B,int rowNumOfA,int colNumOfA,int rowNumOfB,int colNumOfB){
    int i = 0, j = 0, k = 0;
    for(i = 0; i < rowNumOfA ; i++){
        for(j = 0 ; j < colNumOfB ; j++){
            for(k = 0 ; k < colNumOfA ; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void matrixTranspose(int **matrixA_T, int **matrixA, int rowNum, int colNum){
    int i = 0, j = 0;
    for(i = 0; i < rowNum ; i++){
        for(j = 0; j < colNum ; j++){
            matrixA_T[j][i] = matrixA[i][j];
        }
    }
}
int** make2DArray(int n, int m){
    int **arr;
    int id=0;
    arr = (int**)(malloc( sizeof(int*) * n ));
    for(id=0; id < n; id++){
        arr[id] = (int*)(malloc( sizeof(int) * m ) );
    }
    return arr;
}
void free2DArray(int **arr, int n){
    int i = 0;
    for(i=0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
}
void fulfil2DArray(int**arr, int n, int m){
    int i=0, j=0;
    int count =1;
    for(i=0; i<n; i++){
        for(j=0; j<m;j++){
            arr[i][j] = count;
            count++;
        }
    }
}
void print2DArray(int**ptr, int rowNum, int colNum){
    int i=0, j=0;
    for(i=0; i<rowNum ; i++){
        for(j=0; j<colNum; j++){
            printf("%3d ", ptr[i][j]);
        }
        printf("\n");
    }
}