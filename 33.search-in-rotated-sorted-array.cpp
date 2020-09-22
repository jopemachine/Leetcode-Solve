/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

// #define DEBUG

using namespace std;

#ifdef DEBUG
int STACK_DEPTH = 1;
#endif

class Solution {
public:
    int rotatedBinarySearch(vector<int>& nums, int firstIndex, int lastIndex, int target) {
        int medianIndex = (firstIndex + lastIndex) / 2;
        int median = nums[medianIndex];
        int firstValue = nums[firstIndex];
        int lastValue = nums[lastIndex];

        if (firstValue == target) {
            #ifdef DEBUG
            std::cout << "Return first index\n";
            #endif
            return firstIndex;
        }
        if (lastValue == target) {
            #ifdef DEBUG
            std::cout << "Return last index\n";
            #endif
            return lastIndex;
        }  
        if (median == target) {
            #ifdef DEBUG
            std::cout << "Return median index\n";
            #endif
            return medianIndex;
        }

        #ifdef DEBUG
        std::cout << "#########################################\n";
        std::cout << "Stack depth: " << STACK_DEPTH++ << "\n";
        std::cout << "Median Index: " << medianIndex << "\n";
        std::cout << "Median: " << median << "\n";
        std::cout << "firstValue: " << firstValue << "\n";
        std::cout << "lastValue: " << lastValue << "\n";
        std::cout << "firstIndex: " << firstIndex << "\n";
        std::cout << "lastIndex: " << lastIndex << "\n";
        #endif

        if (firstValue < median && median > lastValue) {
            if (target < median) {
                if (target > firstValue) {
                    #ifdef DEBUG
                    std::cout << "Result: 1\n";
                    #endif
                    return rotatedBinarySearch(nums, firstIndex, medianIndex - 1, target);
                }
                else {
                #ifdef DEBUG
                std::cout << "Result: 5\n";
                #endif
                    return rotatedBinarySearch(nums, medianIndex + 1, lastIndex, target);
                }
            } 
            else if (target > median) {
                #ifdef DEBUG
                std::cout << "Result: 2\n";
                #endif
                return rotatedBinarySearch(nums, medianIndex + 1, lastIndex, target);
            }
        }
        else if (firstValue > median && median < lastValue) {
            if (target > median) {
                if (target < lastValue) {
                #ifdef DEBUG
                std::cout << "Result: 3\n";
                #endif
                    return rotatedBinarySearch(nums, medianIndex + 1, lastIndex, target);
                }
                else {
                #ifdef DEBUG
                std::cout << "Result: 6\n";
                #endif
                    return rotatedBinarySearch(nums, firstIndex, medianIndex - 1, target);
                }
            }
            else if (target < median) {
                #ifdef DEBUG
                std::cout << "Result: 4\n";
                #endif
                return rotatedBinarySearch(nums, firstIndex, medianIndex - 1, target);
            }
        }
        // sorted in ascending (normal binary search)
        else {
            if (target > median && target < lastValue) {
                return rotatedBinarySearch(nums, medianIndex + 1, lastIndex, target); 
            }
            else if (target < median && target > firstValue) {
                return rotatedBinarySearch(nums, firstIndex, medianIndex - 1, target);
            }
        }

        #ifdef DEBUG
        std::cout << "Result: Not found\n";
        #endif
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return rotatedBinarySearch(nums, 0, nums.size() - 1, target);
    }
};
// @lc code=end

