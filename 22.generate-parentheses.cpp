/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
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
    vector<string> generateParenthesis(int n) {

        vector<string> result;

        // function signature: string, open parenthesis count, close parenthesis count
        stack<pair<string, pair<int, int>>> stk;

        stk.push({"", { 0, 0 }});

        while(!stk.empty()) {
            // function content
            string str = stk.top().first;

            if(str.size() == n * 2) {
                result.push_back(str);
            }

            pair<int, int> countPair = stk.top().second;
            stk.pop();

            if(countPair.second < countPair.first) {
                stk.push({str + ')', { countPair.first, countPair.second + 1 }});
            }
            if(countPair.first < n) {
                stk.push({str + '(', { countPair.first + 1, countPair.second }});
            }
        }

        return result;
    }
};
// @lc code=end

