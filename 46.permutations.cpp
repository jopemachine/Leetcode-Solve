/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
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
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;

        // selected list, path
        stack<pair<vector<int>, vector<int>>> stk;

        for(int i = 0; i < nums.size(); i++) {
            stk.push({ vector<int> {nums[i]}, vector<int>{i} });
        }

        while(!stk.empty()) {
            vector<int> selectedList = stk.top().first;
            vector<int> path = stk.top().second;
            stk.pop();

            if(selectedList.size() == nums.size()) {
                result.push_back(selectedList);
                continue;
            }

            for (int i = 0; i < nums.size(); i++) {
                if(find(path.begin(), path.end(), i) == path.end()){
                    selectedList.push_back(nums[i]);
                    path.push_back(i);
                    stk.push({ selectedList, path });
                    selectedList.pop_back();
                    path.pop_back();
                }
            }
        }

        return result;
    }
};
// @lc code=end

