/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        for (int i = 0, j = heights.size() - 1; i < j; /* none */) {
            int area = 0;

            if(heights[i] >= heights[j]) {
                area = (j - i) * heights[j];
                j--;
            }
            else {
                area = (j - i) * heights[i];
                i++;
            }

            if(area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};
// @lc code=end

