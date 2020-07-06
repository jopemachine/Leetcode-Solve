/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
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
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
                stk.push(s.at(i));
            }
            else {
                if(stk.empty()) return false;

                char top = stk.top();
                if((top == '(' && s.at(i) == ')') ||
                   (top == '{' && s.at(i) == '}') ||
                   (top == '[' && s.at(i) == ']')) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        if(stk.empty()) {
            return true;
        }

        return false;
    }
};
// @lc code=end

