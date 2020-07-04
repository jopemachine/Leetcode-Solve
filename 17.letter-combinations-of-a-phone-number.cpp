/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start

#include <array>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const unordered_map<int, vector<char>> dialMap = {
    { 2, {'a', 'b', 'c'}},
    { 3, {'d', 'e', 'f'}},
    { 4, {'g', 'h', 'i'}},
    { 5, {'j', 'k', 'l'}},
    { 6, {'m', 'n', 'o'}},
    { 7, {'p', 'q', 'r', 's'}},
    { 8, {'t', 'u', 'v'}},
    { 9, {'w', 'x', 'y', 'z'}}
};

class Solution {
public:

    int toInt(char c) {
        return c - '0';
    }

    string letter_combinations_recursive(vector<string>& result, int index, int max_len, string comb) {
        if(index == max_len) {
            result.push_back(comb);
        }
        else {
            vector<char> values = dialMap.at(index);
            for (int i = 0; i < values.size(); i++) {
                letter_combinations_recursive(result, index + 1, max_len, comb + values[i]);
            }
        }
    }

    // 개인적으로 stack을 사용하는 방법이 휠씬 깔끔하고 맘에 든다.
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if(digits == "") return result;

        // index, result
        stack<pair<int, string>> stk;
        stk.push({ 0, "" });

        // 반복문의 i 변수는 순차적으로 1씩 증가하기 때문에 실행의 흐름을 바꿀 수 없음.
        // 실행의 흐름을 바꾸어야 할 땐 재귀를 쓰거나 (반복문에서 재귀호출), 스택을 사용해야 하는데,
        // 이 때 스택을 사용할 때 스택에 넣어놓아야 할 것은 실행의 흐름에 따라 변하는 값이다.
        // 여기선 인덱스 (index)와 string 값.
        while(!stk.empty()) {
            pair<int, string> top = stk.top();
            stk.pop();
            int index = top.first;
            if(index == digits.size()) result.push_back(top.second);
            else {
                vector<char> values = dialMap.at(toInt(digits.at(index)));
                for (int j = 0; j < values.size(); j++) {
                    stk.push({ index + 1, top.second + values[j] });
                }
            }
        }

        return result;
    }
};
// @lc code=end

