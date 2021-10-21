/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void traverse(TreeNode* root, vector<int> &res) {
        if (!root) return;
        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }

    pair<int, int> findIndex(vector<int> arr) {
        int x = INT_MAX, y = INT_MAX;
        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i] < arr[i - 1]) {
                y = arr[i];
                if (x == INT_MAX) {
                    x = arr[i - 1];
                }
            }
        }
        return {x, y};
    }

    void recover(TreeNode *root, int count, int x, int y) {
        if (!root) return;
        if (root->val == x || root->val == y) {
            root->val == x ? root->val = y : root->val = x;
            if (--count == 0) return; 
        }
        recover(root->left, count, x, y);
        recover(root->right, count, x, y);
    }
public:
    void recoverTree(TreeNode* root) {
        // 中序遍历
        vector<int> res;
        traverse(root, res);
        // 找出index
        auto [x, y] = findIndex(res);
        // 恢复
        recover(root, 2, x, y);
    }
};
// @lc code=end

