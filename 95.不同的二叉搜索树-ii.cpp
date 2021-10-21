/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> generate(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode *> res;
        for (int i = start; i <= end; i ++) {
            vector<TreeNode *> leftTrees = generate(start, i - 1);
            vector<TreeNode *> rightTrees = generate(i + 1, end);
            for (auto &left : leftTrees) {
                for (auto &right : rightTrees) {
                    TreeNode *node = new TreeNode();
                    node->left = left;
                    node->right = right;
                    node->val = i;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};
// @lc code=end

