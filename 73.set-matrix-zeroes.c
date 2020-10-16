/*
 * @lc app=leetcode id=73 lang=c
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start

#include <stdio.h>
#include <memory.h>

// #define DEBUG

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int rowFlags[matrixSize];
    int colFlags[*matrixColSize];

    memset(rowFlags, 0, sizeof(int) * matrixSize);
    memset(colFlags, 0, sizeof(int) * *matrixColSize);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                rowFlags[i] = 1;
                colFlags[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        if (rowFlags[i] == 1) {
            for (int j = 0; j < *matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < *matrixColSize; i++) {
        if (colFlags[i] == 1) {
            for (int j = 0; j < matrixSize; j++) {
                matrix[j][i] = 0;
            }
        }
    }

    #ifdef DEBUG
    printf("\n");
    #endif

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            #ifdef DEBUG
            printf("%d, ", matrix[i][j]);
            #endif
        }
        #ifdef DEBUG
        printf("\n");
        #endif
    }

}


// @lc code=end

