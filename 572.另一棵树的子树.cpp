/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool check(TreeNode *node1, TreeNode *node2) {
        if (!node1 && !node2) {
            return true;
        }
        if (!node1 || !node2) {
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return check(node1->left, node2->left) && check(node1->right, node2->right);
    }

    bool dfs(TreeNode *node1, TreeNode *node2) {
        if (!node1) return false;
        return check(node1, node2) || dfs(node1->left, node2) || dfs(node1->right, node2);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
// @lc code=end

