/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    void visit(TreeNode* root, int sum, vector<int> sumVector, vector<vector<int>>& answer) {
        sumVector.push_back(root->val);
        cout << accumulate(sumVector.begin(), sumVector.end(), 0) << endl;

        if (root->left == nullptr && root->right == nullptr && accumulate(sumVector.begin(), sumVector.end(), 0) == sum)
        {
            answer.push_back(sumVector);
        }
        if (root->left != nullptr) visit(root->left, sum, sumVector, answer);
        if (root->right != nullptr) visit(root->right, sum, sumVector, answer);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> answer;
        if (root == nullptr) return answer;
        visit(root, sum, vector<int> {}, answer);
        return answer;
    }
};
// @lc code=end

