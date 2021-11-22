/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void dfs(TreeNode *root, int &pre, int &res) {
        if (!root) return;
        dfs(root->left, pre, res);
        if (pre == -1) {
            pre = root->val;
        } else {
            res = min(res, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, res);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int pre = -1, res = INT_MAX;
        dfs(root, pre, res);
        return res;
    }
};
// @lc code=end

