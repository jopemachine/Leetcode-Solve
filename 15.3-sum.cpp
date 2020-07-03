/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;

        sort(nums.begin(), nums.end(), [](int x1, int x2) -> bool { return x1 < x2; });

        for (int i = 0; i < nums.size(); i++) {

            if(i >= 1 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1, k = nums.size() - 1; j < k; /* none */) {
                
                int threeSum = nums[i] + nums[j] + nums[k];

                if((j > i + 1 && nums[j] == nums[j - 1]) && (k < nums.size() - 1 && nums[k] == nums[k + 1])) {
                    k--;
                    j++;
                    continue;
                }

                if(threeSum == 0) {
                    // cout << "i: " << i << ", j: " << j << ", k: " << k << "\n";
                    result.push_back(vector ({ nums[i], nums[j], nums[k] }));
                    k--; j++;
                }
                else if(threeSum > 0) k--;
                else j++;
            }
        }

        return result;
    }
};
// @lc code=end

