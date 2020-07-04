/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), [](int x1, int x2) -> bool { return  x1 < x2; });

        pair<int, int> minPair = { INT_MAX, INT_MIN };

        for (int i = 0; i < nums.size(); i++) {

            for (int j = i + 1, k = nums.size() - 1; j < k; /* none */) {
                int threeSum = nums[i] + nums[j] + nums[k];

                if(threeSum == target) {
                    return target;
                }
                else if(threeSum > target) {
                    k--;
                }
                else {
                    j++;
                }

                if(minPair.first > abs(threeSum - target)) {
                    minPair = { abs(threeSum - target), threeSum };
                }
            }
        }

        return minPair.second;
    }
};
// @lc code=end


