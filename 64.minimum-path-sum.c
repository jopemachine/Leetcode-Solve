/*
 * @lc app=leetcode id=64 lang=c
 *
 * [64] Minimum Path Sum
 */

// @lc code=start

#include <stdio.h>
#include <memory.h>

// #define DEBUG

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = *gridColSize;
    int n = gridSize;

    int dp[n][m];
    memset(dp, 0, sizeof(int) * m * n);

    #ifdef DEBUG
    printf("%d\n ", m);
    printf("%d\n ", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d, ", grid[i][j]);
        }
        printf("\n");
    }
    #endif

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[0][0] = grid[0][0];
                continue;
            }
            if (i == 0) {
                dp[0][j] = dp[0][j - 1] + grid[0][j];
                continue;
            }
            if (j == 0) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
                continue;
            }
            const int leastDistance = dp[i][j - 1] < dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
            dp[i][j] = leastDistance + grid[i][j];
        }
    }

    return dp[n-1][m-1];
}
// @lc code=end

