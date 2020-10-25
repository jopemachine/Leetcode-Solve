/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
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

class Solution {
public:

    // O(n^2)
    int longestSubarray(vector<int>& nums) {
        bool zeroNoExist = true;
        vector<int> zeroIndexs;
        // find all 0's indexs
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroIndexs.push_back(i);
                zeroNoExist = false;
            }
        }

        if (zeroNoExist) return nums.size() - 1;

        #ifdef DEBUG
        cout << "--------------------------------" << endl;
        for (int i = 0; i < zeroIndexs.size(); i++) {
            cout << zeroIndexs[i] << endl;
        }
        cout << "--------------------------------" << endl;
        #endif

        // find the longest 1 seq
        int result = 0;
        for (int i = 0; i < zeroIndexs.size(); i++) {
            int currentOneCnt = 0;
            int maxOneCnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (j == zeroIndexs[i]) {
                    continue;
                }

                if (j == nums.size() - 1) {
                    if (nums[j] == 0 && maxOneCnt < currentOneCnt) {
                        maxOneCnt = currentOneCnt;
                    }
                    else if (nums[j] == 1 &&  maxOneCnt < currentOneCnt) {
                        maxOneCnt = currentOneCnt + 1;
                    }
                    break;
                }

                if (nums[j] == 0) {
                    if (maxOneCnt < currentOneCnt) {
                        maxOneCnt = currentOneCnt;
                    }
                    currentOneCnt = 0;
                }
                else {
                    currentOneCnt++;
                }
            }

            #ifdef DEBUG
            cout << "i:            " << i << endl;
            cout << "zeroIndex:    " << zeroIndexs[i] << endl;
            cout << "maxOneCnt:    " << maxOneCnt << endl;
            #endif

            if (result < maxOneCnt) {
                result = maxOneCnt;
            }
        }

        return result;
    }
};
// @lc code=end

