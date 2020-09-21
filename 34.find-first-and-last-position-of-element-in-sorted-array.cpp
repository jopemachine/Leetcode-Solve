/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
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

// #define DEBUG

class Solution {
public:

    int binarySearch(vector<int>& nums, int startingIndex, vector<int>& result, int target) {
        int medianIndex = nums.size() / 2;
        int median = nums[medianIndex];
        int offset = nums.size() - medianIndex;
        if (median > target) {
            if (nums.size() == 1) {
                return -1;
            }

            #ifdef DEBUG
            cout << "Starting Index: " << startingIndex << "\n";

            for (int i = 0; i < nums.size(); i++) {
               cout << i << " th nums: " << nums[i];
            }
            #endif

            vector<int> leftArr = vector<int>(nums.begin(), nums.end() - offset);
            return binarySearch(leftArr, startingIndex, result, target);
        } 
        else if (median < target) {
            if (nums.size() == 1) {
                return -1;
            }

            #ifdef DEBUG
            cout << "Starting Index: " << startingIndex << "\n";

            for (int i = 0; i < nums.size(); i++) {
               cout << i << " th nums: " << nums[i] << "\n";
            }
            #endif

            vector<int> rightArr = vector<int>(nums.begin() + offset, nums.end());
            int newStartingPoint = nums.size() % 2 == 1 ? startingIndex + medianIndex + 1 : startingIndex + medianIndex;
            return binarySearch(rightArr, newStartingPoint, result, target);
        } 
        // median == target
        else {

            #ifdef DEBUG
            cout << "Starting Index: " << startingIndex << "\n";

            for (int i = 0; i < nums.size(); i++) {
               cout << i << " th nums: " << nums[i] << "\n";
            }
            #endif

            int maxIndex = medianIndex;
            while ((maxIndex + 1 < nums.size()) && (nums[maxIndex + 1] == median)) { maxIndex++; }
            result.push_back(maxIndex + startingIndex);

            int minIndex = medianIndex;
            while ((minIndex - 1 >= 0) && (nums[minIndex - 1] == target)) { minIndex--; }
            result.insert(result.begin(), minIndex + startingIndex);

            return medianIndex;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() < 1) return { -1, -1 };
        vector<int> result = {};
        if (binarySearch(nums, 0, result, target) == -1) return { -1, -1 };
        return result;
    }
};
// @lc code=end

