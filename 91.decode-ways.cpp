/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
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

    int dfs(int index, string str, unordered_map<int, int>& dp) {
        if (index == str.length()) {
            return 1;
        }

        if (str.at(index) == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }
        auto iter = dp.find(index);
        if (iter != dp.end()) {
            return iter->second;
        }

        int cnt = dfs(index + 1, str, dp);
        if (stoi(str.substr(index, 2)) <= 26) {
            cnt += dfs(index + 2, str, dp);
        }

        dp.insert({ index, cnt });
        return cnt;
    }

    int numDecodings(string s) {
        if (s.length() == 0) {
            return 0;
        }

        unordered_map<int, int> dp;
        return dfs(0, s, dp);
    }
};
// @lc code=end

