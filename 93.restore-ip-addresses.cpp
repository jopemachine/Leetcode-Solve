/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
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

    bool isValidIp (string str) {
        if (str.size() < 7) return false;

        string nums[4] = {"", "", "", ""};
        char spliter = '.';

        int numsIdx = 0;
        string buf = "";
        for (int i = 0; i < str.size(); i++) {
            if (i == str.size() - 1) {
                if (buf.size() > 4) return false;
                nums[3] = buf + str.at(i);
                break;
            }
            if (str.at(i) == spliter) {
                if (buf.size() > 4 || stoi(buf) > 255) return false; 
                nums[numsIdx++] = buf;
                buf = "";
            }
            else {
                buf += str.at(i);
            }
        }

        for (int i = 0; i < 4; i++) {
            if (stoi(nums[i]) > 255 || nums[i] == "" || (nums[i].at(0) == '0' && nums[i].size() != 1) ) return false;
        }

        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) {
            return vector<string> {};
        }

        vector<string> outputs;
        stack<pair<string, int>> stk;

        int strIdx = 0;
        string str(string(1, s[strIdx]));
        stk.push({ str, 0 });
        while (!stk.empty()) {
            pair<string, int> top = stk.top();
            stk.pop();

            if (top.second >= 3) {
                string remainingStr = s.substr(top.first.size() - 3, -1);

                if (isValidIp(top.first + remainingStr))
                {
                    outputs.push_back(top.first + remainingStr);
                }

            } else {
                if (top.first.size() - top.second < s.size()) {
                    if (top.first.at(top.first.size() - 1) != '.') {
                        stk.push({ top.first + "." , top.second + 1 });
                    }
                    stk.push({ top.first + string(1, s[top.first.size() - top.second]) , top.second });
                }
            }
        }
        return outputs;
    }
};
// @lc code=end

