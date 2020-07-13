/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> arr;
        arr.reserve(matrix.size() * matrix.size());

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                arr.push_back(matrix[i][j]);
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int rowIndex = i / matrix.size();
            int colIndex = i % matrix.size();

            matrix[colIndex] [matrix.size() - rowIndex - 1] = arr[i];
        }
    }
};
// @lc code=end

