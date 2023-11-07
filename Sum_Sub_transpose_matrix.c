#include <stdio.h>
#include <stdlib.h>

void matrixSum(int **mat1, int **mat2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void matrixSubtraction(int **mat1, int **mat2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void matrixTranspose(int **mat, int rows, int cols) {
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void displayMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of Matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of Matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Matrix 1:\n");
    displayMatrix(matrix1, rows, cols);

    printf("\nMatrix 2:\n");
    displayMatrix(matrix2, rows, cols);

    printf("\nMatrix Sum:\n");
    matrixSum(matrix1, matrix2, result, rows, cols);
    displayMatrix(result, rows, cols);

    printf("\nMatrix Subtraction:\n");
    matrixSubtraction(matrix1, matrix2, result, rows, cols);
    displayMatrix(result, rows, cols);

    printf("\nTranspose of Matrix 1:\n");
    matrixTranspose(matrix1, rows, cols);
    displayMatrix(matrix1, cols, rows);

    printf("\nTranspose of Matrix 2:\n");
    matrixTranspose(matrix2, rows, cols);
    displayMatrix(matrix2, cols, rows);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
