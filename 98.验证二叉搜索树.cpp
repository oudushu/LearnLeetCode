/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // bool check(TreeNode *root, TreeNode *leftNode, TreeNode *rightNode) {
    //     if (!root) return true;
    //     if (leftNode && root->val <= leftNode->val) return false;
    //     if (rightNode && root->val >= rightNode->val) return false;
    //     return check(root->left, leftNode, root) && check(root->right, root, rightNode);
    // }

    bool check(TreeNode *root, TreeNode *leftNode, TreeNode *rightNode) {
        if (!root) return true;
        if (leftNode && leftNode->val >= root->val) return false;
        if (rightNode && rightNode->val <= root->val) return false;
        return check(root->left, leftNode, root) && check(root->right, root, rightNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, nullptr, nullptr);
    }
};
// @lc code=end

