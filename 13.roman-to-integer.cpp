/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        for (int i = 0; i < s.size(); i++) {
            if(s.at(i) == 'I') {
                if(i != s.size() - 1) {
                    if(s.at(i + 1) == 'V') {
                        result += 4;
                        i++;
                        continue;
                    } 
                    else if(s.at(i + 1) == 'X') {
                        result += 9;
                        i++;
                        continue; 
                    }
                }
                result += 1;
            } 
            if(s.at(i) == 'V') {
                result += 5;
            }
            if(s.at(i) == 'X') {
                if(i != s.size() - 1) {
                    if(s.at(i + 1) == 'L') {
                        result += 40;
                        i++;
                        continue;
                    } 
                    else if(s.at(i + 1) == 'C') {
                        result += 90;
                        i++;
                        continue; 
                    }
                }
                result += 10;
            }
            if(s.at(i) == 'L') {
                result += 50;
            }
            if(s.at(i) == 'C') {
                if(i != s.size() - 1) {
                    if(s.at(i + 1) == 'D') {
                        result += 400;
                        i++;
                        continue;
                    } 
                    else if(s.at(i + 1) == 'M') {
                        result += 900;
                        i++;
                        continue; 
                    }
                }
                result += 100;
            }
            if(s.at(i) == 'D') {
                result += 500;
            }
            if(s.at(i) == 'M') {
                result += 1000;
            }
        }
        return result;
    }
};
// @lc code=end

