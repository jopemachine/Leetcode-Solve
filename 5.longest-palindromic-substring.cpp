/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:

    pair<int, int> expandAroundCenter(string input, int j, int k) {

        while (j >= 0 && k < input.size())
        {
            // not palindrome
            if (input.at(j) != input.at(k))
            {
                break;
            }
            j--;
            k++;
        }

        return make_pair(j + 1, k - 1);
    }

    string longestPalindrome(string input) {
        
        if(input == "" || input.size() == 1) return input;

        pair<int, int> longest = { 0, 0 };

        for(int i = 0; i < input.size(); i++) {
            pair<int, int> res;

            auto res1 = expandAroundCenter(input, i, i);
            auto res2 = expandAroundCenter(input, i, i + 1);
            
            if(res1.second - res1.first >= res2.second - res2.first) res = res1;
            else res = res2;

            longest = res.second - res.first > longest.second - longest.first ? res : longest;
        }

        return input.substr(longest.first, longest.second - longest.first + 1);
    }
};
// @lc code=end


