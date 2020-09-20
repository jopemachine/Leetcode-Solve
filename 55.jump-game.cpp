/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
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
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1 && nums[0] == 0) return true;

        int maxValueBuffer = -1;
        int maxValueIndexBuffer = -1;
        int tempMaxValueBuffer = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (tempMaxValueBuffer - 1 <= nums[i]) {
                maxValueBuffer = nums[i];
                maxValueIndexBuffer = i;
                tempMaxValueBuffer = maxValueBuffer;
            }
            else {
                tempMaxValueBuffer -= 1;
            }

            const int minimumValue = i == nums.size() - 1 ? i - maxValueIndexBuffer : i - maxValueIndexBuffer + 1;
            if (maxValueBuffer < minimumValue)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

