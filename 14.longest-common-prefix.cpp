/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0) return "";

        string s = "";

        int shortestLen = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (shortestLen > strs[i].size()) shortestLen = strs[i].size();
        }

        for (int i = 0; i < shortestLen; i++) {
            char ch = strs[0].at(i);
            for (int j = 0; j < strs.size(); j++) {
                if (ch != strs[j].at(i)) return s;
            }
            s += (ch);
        }

        return s;
    }
};
// @lc code=end

