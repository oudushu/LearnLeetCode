/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    bool isNode(TreeNode *node) {
        return !node->left && !node->right;
    }

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int res = 0;
        if (node->left) {
            res += isNode(node->left) ? node->left->val : dfs(node->left);;
        }

        if (node->right && !isNode(node->right)) {
            res += dfs(node->right);
        }
        return res;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};
// @lc code=end

