/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

// #define DEBUG

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];
        memset(dp, 0, sizeof(int) * n);
        for (int i = 0; i < m; i++) {
            memset(dp[i], 0, sizeof(int) * n);
        }

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        dp[0][0] = 1;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                int left = x == 0 || obstacleGrid[y][x-1] == 1 ? 0 : dp[y][x-1];
                int top = y == 0 || obstacleGrid[y-1][x] == 1 ? 0 : dp[y-1][x];
                if (x == 0 && y == 0) {
                    dp[0][0] = 1;
                    continue;
                }
                dp[y][x] = obstacleGrid[y][x] == 1 ? 0 : left + top;
            }
        }

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                #ifdef DEBUG
                cout << dp[y][x] << ", ";
                #endif
            }
            #ifdef DEBUG
            cout << "\n";
            #endif
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

