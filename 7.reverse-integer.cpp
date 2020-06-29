/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
using namespace std;

#include <iostream>
#include <limits.h>

class Solution {
public:
    long abs(long x) {
        return x < 0 ? x * -1 : x;
    }

    long square(int x, int n) {
        // assume n >= 0
        if(n == 0) return 1;
        long result = x;
        while (--n > 0) {
            result *= x;
        }
        return result;
    }

    int reverse(int x) {
        // 1 - Use string (char *) convert.
        // ** skip on here..

        // 2 - Use Math
        long result = 0;
        int orig = x; // 123

        int h = 0;
        long absx = abs(x);
        while((absx = (absx / 10)) >= 1) { h++; }

        while(h >= 0) {
            int rest = orig % 10;
            result += square(10, h--) * rest;
            if(result > INT_MAX || result < INT_MIN) return 0;
            orig /= 10;
        }

        return (int) result;
    }
};
// @lc code=end

