/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
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
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row condition
        for (int row = 0; row < 9; row++) {
            bool check[9] { false };
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') continue;
                if (check[board[row][col] - 48 - 1] != false) {
                    return false;
                }
                else {
                    check[board[row][col] - 48 - 1] = true;
                }
            }
        }

        // check col condition
        for (int col = 0; col < 9; col++) {
            bool check[9] { false };
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.') continue;
                if (check[board[row][col] - 48 - 1] != false) {
                    return false;
                }
                else {
                    check[board[row][col] - 48 - 1] = true;
                }
            }
        }

        // check 3 * 3 sub-boxes
        for (int subBoxesRow = 0; subBoxesRow < 3; subBoxesRow++) {
            for (int subBoxesCol = 0; subBoxesCol < 3; subBoxesCol++) {
                bool check[9] { false };
                for (int subBoxesIndex = 0; subBoxesIndex < 9; subBoxesIndex++) {

                    int colSubIndex = subBoxesIndex >= 6 ? subBoxesIndex - 6 : subBoxesIndex >= 3 ? subBoxesIndex - 3 : subBoxesIndex;
                    int col = (subBoxesCol * 3 + colSubIndex);
                    int row = (subBoxesRow * 3 + (subBoxesIndex / 3));

                    if (board[row][col] == '.') continue;

                    if (check[board[row][col] - 48 - 1] != false) {
                        return false;
                    }
                    else {
                        check[board[row][col] - 48 - 1] = true;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end

