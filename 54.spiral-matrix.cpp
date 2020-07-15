/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int> {};

        vector<int> result;

        int colSize = matrix.size();
        int rowSize = matrix[0].size();

        if(colSize == 1) return matrix[0];
        if(rowSize == 1) {
            for (int i = 0; i < colSize; i++) {
                result.push_back(matrix[i][0]);
            }
            return result;
        }

        vector<vector<bool>> isVisited;

        for (int i = 0; i < colSize; i++) {
            vector<bool> vec;
            for (int j = 0; j < rowSize; j++) {
                vec.push_back(false);
            }
            isVisited.push_back(vec);
        }

        int direction = 0;
        int rowIndex = 0;
        int colIndex = 0;

        while(!isVisited[colIndex][rowIndex]) {
            result.push_back(matrix[colIndex][rowIndex]);
            isVisited[colIndex][rowIndex] = true;

            if(direction == 0) {
                if((rowIndex + 1 >= rowSize || isVisited[colIndex][rowIndex + 1])) {
                    direction = 1;
                    colIndex++;
                } 
                else {
                    rowIndex++;
                }
            }
            else if(direction == 1) {
                if((colIndex + 1 >= colSize || isVisited[colIndex + 1][rowIndex])) {
                    direction = 2;
                    rowIndex--;
                } 
                else {
                    colIndex++;
                }
            }
            else if(direction == 2) {
                if((rowIndex - 1 < 0 || isVisited[colIndex][rowIndex - 1])) {
                    direction = 3;
                    colIndex--;
                } 
                else {
                    rowIndex--;
                }
            }
            else if(direction == 3){
                if((colIndex - 1 < 0 || isVisited[colIndex - 1][rowIndex])) {
                    direction = 0;
                    rowIndex++;
                } 
                else {
                    colIndex--;
                }
            }
        }

        return result;
    }
};
// @lc code=end

