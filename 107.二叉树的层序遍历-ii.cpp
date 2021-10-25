/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            int size = myQueue.size();
            vector<int> valArr;
            for (int i = 0; i < size; i ++) {
                TreeNode *node = myQueue.front();
                myQueue.pop();
                valArr.push_back(node->val);
                if (node->left) {
                    myQueue.push(node->left);
                }
                if (node->right) {
                    myQueue.push(node->right);
                }
            }
            res.push_back(valArr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

