/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        array<int, 26> cnts;

        unordered_map<string, vector<string>> map;

        for (int i = 0; i < strs.size(); i++) {
            fill(cnts.begin(), cnts.end(), 0);
            const string str = strs[i];

            for (int j = 0; j < str.size(); j++) {
                cnts[str.at(j) - 'a']++;
            }

            string hashKey = "";
            for (int i = 0; i < cnts.size(); i++) {
                hashKey += "#" + to_string(cnts[i]);
            }

            if(map.find(hashKey) != map.end()) {
                map.at(hashKey).push_back(str);
            } 
            else {
                map.insert({hashKey, vector {str}});
            }
        }

        auto it = map.begin();

        while(it != map.end())
        {
            result.push_back(it->second);
            it++;
        }

        return result;
    }
};
// @lc code=end

