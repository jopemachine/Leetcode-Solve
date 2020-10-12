/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
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

#define DEBUG

class Solution {
public:
    int floorMod(int x, int n) {
        return ((x % n) + n) % n;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n));
        const int dir[][2] = {{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }};

        int cnt = 1;
        int x = 0;
        int y = 0;
        int d = 0;
        while (cnt <= n * n) {
            result[y][x] = cnt++;
            int nx = floorMod(x + dir[d][1], n);
            int ny = floorMod(y + dir[d][0], n);
            if (result[ny][nx] != 0) d = (d + 1) % 4;
            x += dir[d][1];
            y += dir[d][0];
        }
        return result;
    }
};
// @lc code=end