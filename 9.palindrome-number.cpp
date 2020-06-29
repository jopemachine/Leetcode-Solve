/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start

#include <iostream>

using namespace std;

class Solution {
public:
    long square(int x, int n) {
        // assume n >= 0
        if(n == 0) return 1;
        long result = x;
        while (--n > 0) {
            result *= x;
        }
        return result;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        int _x = x;
        int h = 0;
        while(_x /= 10) h++;
        _x = x;

        int origX = x;
        int origH = h;

        while(true) {
            if(h <= origH / 2) break;
            int div = _x % square(10, h);

            if(((origX / square(10, h)) % 10) != _x % 10) return false;
            h--;
            _x /= 10;
        }
        return true;
    }
};
// @lc code=end

