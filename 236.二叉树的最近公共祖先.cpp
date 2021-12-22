/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    map<int, TreeNode *> fatherMap;
    map<int, bool> visited;

    void traverse(TreeNode *root) {
        if (root->left) {
            fatherMap[root->left->val] = root;
            traverse(root->left);
        }
        if (root->right) {
            fatherMap[root->right->val] = root;
            traverse(root->right);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fatherMap[root->val] = nullptr;
        traverse(root);
        while (p) {
            visited[p->val] = true;
            p = fatherMap[p->val];
        }
        while (q) {
            if (visited[q->val]) {
                return q;
            }
            q = fatherMap[q->val];
        }
        return nullptr;
    }
};
// @lc code=end

