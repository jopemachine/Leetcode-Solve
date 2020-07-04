/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            // number, index
            map.insert({ nums[i], i });
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // find complement among the key
            if(map.count(complement)) {
                // if below key exist, two sum condition satisfy
                if(i != map.at(complement)) {
                    res = { i, map.at(complement) };
                    return res;
                }
            }

            // inefficient search

            // for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it) {
            //  ....
            // }
        }
        return res;
    }

    vector<int> twoSum_BruteForce(vector<int>& nums, int target) {
        
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

        return res;
    }
};
// @lc code=end

