/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
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
    vector<int> grayCode(int n) {
        vector<vector<int>> dp = vector(n + 1, vector<int>());

        dp[0].push_back(0);

        if (n == 0) return dp[0];

        dp[1].push_back(0);
        dp[1].push_back(1);

        for (int i = 2; i <= n; i++) {
            // copy Zero part
            for (int j = 0; j < dp[i - 1].size(); ++j) {
                dp[i].push_back(dp[i - 1][j]);
            }

            int powVal = pow(2, i - 1);
            // copy One part
            for (int j = dp[i - 1].size() - 1; j >= 0; --j) {
                dp[i].push_back(powVal + dp[i - 1][j]);
            }
        }

        return dp[n];
    }
};
// @lc code=end

