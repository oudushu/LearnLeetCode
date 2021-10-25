/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode *> myQueue;
        myQueue.push(root);
        int count = 0;
        while (!myQueue.empty()) {
            count ++;
            int size = myQueue.size();
            for (int i = 0; i < size; i ++) {
                TreeNode *node = myQueue.front();
                myQueue.pop();
                if (!node->left && !node->right) {
                    return count;
                }
                if (node->left) {
                    myQueue.push(node->left);
                }
                if (node->right) {
                    myQueue.push(node->right);
                }
            }
        }
        return 0;
    }
};
// @lc code=end

