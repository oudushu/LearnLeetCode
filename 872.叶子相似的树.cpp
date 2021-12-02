/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    void dfs(TreeNode *root, vector<int> &res) {
        if (!root->left & !root->right) {
            res.push_back(root->val);
            return;
        }
        if (root->left) {
            dfs(root->left, res);
        }
        if (root->right) {
            dfs(root->right, res);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        if (root1) {
            dfs(root1, res1);
        }
        vector<int> res2;
        if (root2) {
            dfs(root2, res2);
        }
        return res1 == res2;
    }
};
// @lc code=end

