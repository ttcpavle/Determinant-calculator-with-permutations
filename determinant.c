#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Det(int** matrix, int n);
void permute(int* permutation, int** matrix, int start, int end, int* determinant, int parity);
void SumDet(int n, int arr[], int** matrix, int* determinant, int parity);
int** RandomMatrix(int n);


inline void swap(int* arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
//determinant calculator
int Det(int** matrix, int n) {
    int Determinant = 0;
    int* permutation = (int*)malloc(n * sizeof(int));

    if (permutation == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    permute(permutation, matrix, 0, n, &Determinant, 1);

    free(permutation);
    return Determinant;
}
//recursive permutation algorithm
void permute(int* permutation, int** matrix, int start, int end, int* determinant, int parity) {
    int i;
    int n = end;

    if (start == end) {
        SumDet(n, permutation, matrix, determinant, parity);
        return;
    }

    permute(permutation, matrix, start + 1, end, determinant, parity);

    for (i = start + 1; i < end; i++) {
        if (permutation[start] == permutation[i]) continue;

        swap(permutation, start, i);
        permute(permutation, matrix, start + 1, end, determinant, parity * (-1));
        swap(permutation, start, i);
    }
}
//adds new number to sum of determinant
void SumDet(int n, int arr[], int** matrix, int* determinant, int parity) {
    int x = 1;
    for (int i = 0; i < n; i++) {
        x *= matrix[i][arr[i] - 1];
    }
    *determinant += parity * x;
}
//random matrix generator
int** RandomMatrix(int n) {
    srand(time(NULL));
    int** matrix = (int**)malloc(n * sizeof(int*));

    if (matrix == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("memory allocation failed\n");
            //this will first deallocate previously allocated memory if allocation fails
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //you can edit modulo for random numbers
            matrix[i][j] = rand() % 10000 + 1;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return matrix;
}

int main(int argc, char** argv) {
    int dim;
    printf("Enter dimension n of nxn matrix:"); // NOTE: larger matrces will take much longer to process
    scanf_s("%d", &dim);
    printf("Matrix:\n");
    int** matrix = RandomMatrix(dim);
    if (matrix == NULL) {
        return 1;
    }

    clock_t begin = clock();
    printf("Determinant is: %d\n", Det(matrix, dim));
    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %lf", time_spent);
    
    for (int i = 0; i < dim; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
