/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

    void treeToList(TreeNode* root, vector<int>& list) {
        if (root->left != nullptr) treeToList(root->left, list);
        list.push_back(root->val);
        if (root->right != nullptr) treeToList(root->right, list);
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        vector<int> list;
        treeToList(root, list);

        for (int i = 0; i < list.size() - 1; i++) {
            if (list[i] >= list[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

