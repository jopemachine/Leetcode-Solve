/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> cache = vector<vector<int>>(triangle.size(), vector<int>(0));

        cache[0].push_back(triangle[0][0]);

        for (int h = 1; h < triangle.size(); h++) {
            for (int j = 0; j < triangle[h].size(); j++) {
                if (j < 1) {
                    cache[h].push_back(cache[h - 1][j] + triangle[h][j]);
                    continue;
                } else if (j == triangle[h].size() - 1) {
                    cache[h].push_back(cache[h - 1][j - 1] + triangle[h][j]);
                    continue;
                }

                int left = cache[h - 1][j - 1] + triangle[h][j];
                int right = cache[h - 1][j] + triangle[h][j];

                if (left <= right) {
                    cache[h].push_back(left);
                } 
                else if (left > right) {
                    cache[h].push_back(right);
                }
            }
        }

        return *min_element(cache[triangle.size() - 1].begin(), cache[triangle.size() - 1].end());
    }
};
// @lc code=end

