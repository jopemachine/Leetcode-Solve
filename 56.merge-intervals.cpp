/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
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

    bool isMergable(vector<int>& left, vector<int>& right) {
        return right[0] <= left[1];
    }

    int max(int x1, int x2) {
        return x1 > x2 ? x1 : x2;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), [](vector<int>& x1, vector<int>& x2) -> bool {
            if (x1[0] > x2[0]) {
                return false;
            } 
            else if (x1[0] < x2[0]) {
                return true;
            }
            else {
                if (x1[1] < x2[1]) {
                    return true;
                }
                else if (x1[1] > x2[1]) {
                    return false;
                }
                // 왜인지 모르겠는데, 반드시 false를 반환해 줘야 됨
                return false;
            }
        });

        for (int i = 0; i < intervals.size(); i++) {
            int j = i;
            vector<int>& target = intervals[i];
            while (j < intervals.size() - 1 && isMergable(intervals[i], intervals[j + 1])) {
                target[1] = max(intervals[j + 1][1], intervals[i][1]);
                j++;
            }
            i = j;

            result.push_back(target);
        }

        return result;
    }
};
// @lc code=end

