//KAMANDE KENNEDY KAMAU
//ENE212-0169/2021


#include <stdio.h>

#define ROW1 2
#define COL1 3
#define ROW2 3
#define COL2 2

void inputMatrix(int matrix[][COL1], const char *name) {
    int i, j;
    printf("Enter elements for %s:\n", name);
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL1; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][COL1], const char *name) {
    int i, j;
    printf("\n%s:\n", name);
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL1; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[][COL1], int matrixB[][COL1], int result[][COL1]) {
    int i, j;
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL1; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[][COL1], int matrixB[][COL1], int result[][COL1]) {
    int i, j;
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL1; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[][COL1], int matrixB[][COL2], int result[][COL2]) {
    int i, j, k;
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            result[i][j] = 0;
            for (k = 0; k < COL1; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrixA[ROW1][COL1], matrixB[ROW2][COL2], sum[ROW1][COL1], diff[ROW1][COL1], product[ROW1][COL2];

    inputMatrix(matrixA, "Matrix A");
    inputMatrix(matrixB, "Matrix B");

    displayMatrix(matrixA, "Matrix A");
    displayMatrix(matrixB, "Matrix B");

    addMatrices(matrixA, matrixB, sum);
    printf("Sum of matrices:\n");
    displayMatrix(sum, "A + B");

    subtractMatrices(matrixA, matrixB, diff);
    printf("Difference of matrices:\n");
    displayMatrix(diff, "A - B");

    if (COL1 == ROW2) {
        multiplyMatrices(matrixA, matrixB, product);
        printf("Product of matrices:\n");
        displayMatrix(product, "A * B");
    } else {
        printf("Error: Matrices cannot be multiplied due to mismatched dimensions.\n");
    }

    return 0;
}
