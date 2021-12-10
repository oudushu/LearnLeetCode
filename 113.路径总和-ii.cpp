/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void trackback(vector<vector<int>> &res, vector<int> &track, TreeNode *root, int targetSum) {
        if (!root) return;
        track.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0) {
            res.push_back(track);
        }
        trackback(res, track, root->left, targetSum);
        trackback(res, track, root->right, targetSum);
        track.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> track;
        trackback(res, track, root, targetSum);
        return res;
    }
};
// @lc code=end

