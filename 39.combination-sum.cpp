/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
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

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        // selected list, index, sum
        stack<pair<vector<int>, pair<int, int>>> stk;

        sort(candidates.begin(), candidates.end(), [](int x1, int x2) -> bool { return x1 < x2; });

        for (int i = 0; i < candidates.size(); i++) {
            stk.push({ vector { candidates[i] }, { i, candidates[i] } });
        }

        while(!stk.empty()) {
            auto list = stk.top().first;
            int index = stk.top().second.first;
            int sum = stk.top().second.second;
            stk.pop();

            if(sum == target) {
                result.push_back(list);
                continue;
            }
            else if (sum > target) {
                continue;
            }

            for (int i = index; i < candidates.size(); i++) {
                vector<int> copy = list;
                copy.push_back(candidates[i]);
                stk.push({ copy, { i, sum + candidates[i]} });
            }
        }

        return result;
    }
};
// @lc code=end

