/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> myQueue;
        myQueue.push(root);
        int level = 0;
        while (!myQueue.empty()) {
            int size = myQueue.size();
            vector<int> arr;
            for (int i = 0; i < size; i ++) {
                TreeNode *node = myQueue.front();
                myQueue.pop();
                arr.push_back(node->val);
                if (node->left) myQueue.push(node->left);
                if (node->right) myQueue.push(node->right);
            }
            if (level % 2 == 1) {
                reverse(arr.begin(), arr.end());
            }
            res.push_back(arr);
            ++ level;
        }
        return res;
    }
};
// @lc code=end

