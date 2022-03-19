/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxVal = INT_MIN;

    int maxSum(TreeNode *node) {
        if (!node) return 0;

        int leftMaxVal = max(maxSum(node->left), 0);
        int rightMaxVal = max(maxSum(node->right), 0);

        int sumVal = leftMaxVal + rightMaxVal + node->val;

        maxVal = max(maxVal, sumVal);

        return node->val + max(leftMaxVal, rightMaxVal);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxVal;
    }
};
// @lc code=end

