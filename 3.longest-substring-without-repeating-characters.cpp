/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s == "") return 0;

        int result = 1;
        int exist = 0;
        unordered_set<char> previousPattern;

        for (int i = 0, j = 0; i < s.size() && j < s.size();) {
            // exist
            if(find(previousPattern.begin(), previousPattern.end(), s.at(i)) != previousPattern.end()) {

                // j is moved when duplicate character exist
                previousPattern.erase(s.at(j++));
                
                // cout << "---------------------------------------------------------" << endl;
                // cout << "a1" << endl;
                // cout << "i: " << i << ", ith:"  << s.at(i) << endl;
                // cout << "j: " << j << ", jth:"  << s.at(j) << endl;
                // cout << "---------------------------------------------------------" << endl;
            } 
            // not exist
            else {
                // cout << "---------------------------------------------------------" << endl;
                // cout << "a2" << endl;
                previousPattern.insert(s.at(i++));
                result = max(i - j, result);
                // cout << "i: " << i << ", ith:"  << s.at(i) << endl;
                // cout << "j: " << j << ", jth:"  << s.at(j) << endl;
                // cout << "---------------------------------------------------------" << endl;
            }
        }

        return result;
    }

    int bruteForce(string s) {
        
        if(s == "") return 0;
        
        vector<int> resArr = { 1 };

        for (int i = 0; i < s.size(); i++) {
            int res = 0;
            vector<char> previousPattern;
            for (int j = i; j < s.size(); j++) {
                // exist
                if(find(previousPattern.begin(), previousPattern.end(), s.at(j)) != previousPattern.end()) {
                    resArr.push_back(res);
                    break;
                }
                // not exist
                else {
                    res++;
                    previousPattern.push_back(s.at(j));
                }
                // whole string is the case
                if(j == s.size() - 1) {
                    resArr.push_back(res);
                }
            }
        }

        // for(int i = 0; i < resArr.size(); i++) {
        //     cout << "i: " << resArr[i] << endl;
        // }

        int maxValue = *max_element(resArr.begin(), resArr.end());
        return maxValue;
    }
};
// @lc code=end

