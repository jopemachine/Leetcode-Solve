/*
 * @lc app=leetcode id=74 lang=c
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start

// #define DEBUG

#include <stdio.h>

bool binarySearch(int* array, int startIdx, int endIdx, int target) {
    if (endIdx - startIdx <= 1) {
        return (array[startIdx] == target || array[endIdx] == target);
    }

    int medianIdx = (startIdx + endIdx) / 2;
    if (array[medianIdx] < target) {
        return binarySearch(array, medianIdx + 1, endIdx, target);
    } 
    else if (array[medianIdx] > target) {
        return binarySearch(array, startIdx, medianIdx - 1, target);
    }
    else {
        return true;
    }
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }

    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == target) {
            return true;
        }
        else if (matrix[i][0] < target && i < matrixSize - 1 && matrix[i+1][0] > target) {
            return binarySearch(matrix[i], 0, *matrixColSize - 1, target);
        }
        else if (matrix[i][0] < target && i == matrixSize - 1) {
            return binarySearch(matrix[i], 0, *matrixColSize - 1, target);
        }
    }
    return false;
}
// @lc code=end

