/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
private:
    void traverse(TreeNode* root, vector<TreeNode*> &arr) {
        if (!root) return;
        arr.push_back(root);
        traverse(root->left, arr);
        traverse(root->right, arr);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> arr;
        traverse(root, arr);
        for (int i = 1; i < arr.size(); i ++) {
            TreeNode *pre = arr[i - 1];
            TreeNode *cur = arr[i];
            pre->left = nullptr;
            pre->right = cur;
        }
    }
};
// @lc code=end

