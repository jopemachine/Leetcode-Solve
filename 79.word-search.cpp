/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
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

int rowCnt;
int colCnt;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rowCnt = board.size();
        colCnt = board[0].size();

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs (vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index >= word.size()) {
            return true;
        }

        if (row < 0 || row == rowCnt || col < 0 || col == colCnt || board[row][col] != word[index])
        {
            return false;
        }

        bool ret = false;

        board[row][col] = '#';
        int rowOffsets[] = { 0, 1, 0, -1 };
        int colOffsets[] = { 1, 0, -1, 0 };
        for (int d = 0; d < 4; ++d) {
            ret = dfs(board, word, row + rowOffsets[d], col + colOffsets[d], index + 1);
            if (ret) break;
        }

        board[row][col] = word[index];
        return ret;
    }
};
// @lc code=end

