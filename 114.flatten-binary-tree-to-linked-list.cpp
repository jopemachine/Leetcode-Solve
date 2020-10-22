/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

using namespace std;

class Solution {
public:

    TreeNode* visit(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }

        TreeNode* left = visit(root->left);
        TreeNode* right = visit(root->right);

        if (left != nullptr) {
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        return right == nullptr ? left : right;
    }


    void flatten(TreeNode* root) {
        visit(root);
    }
};
// @lc code=end

