/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    int leftMax(TreeNode *root) {
        root = root->left;
        while (root->right) {
            root = root->right;
        }
        return root->val;
    }

    int rightMin(TreeNode *root) {
        root = root->right;
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }

    bool isLeafNode(TreeNode *root) {
        return !root->left && !root->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (isLeafNode(root)) {
                delete root;
                root = nullptr;
            } else if (root->right) {
                root->val = rightMin(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                root->val = leftMax(root);
                root->left = deleteNode(root->left, root->val);
            }
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};
// @lc code=end

