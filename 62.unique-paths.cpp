/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
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

// #define DEBUG

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(int) * m * n);

        dp[0][0] = 1;
        for (int y = 1; y < m; y++) {
            dp[y][0] = 1;
        }
        for (int x = 1; x < n; x++) {
            dp[0][x] = 1;
        }

        for (int y = 1; y < m; y++) {
            for (int x = 1; x < n; x++) {
                dp[y][x] = dp[y][x-1] + dp[y-1][x];
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

