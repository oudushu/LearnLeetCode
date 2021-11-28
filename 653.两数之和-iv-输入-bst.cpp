/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    set<int> mySet;

    bool find(TreeNode* root, int k) {
        if (!root) return false;
        if (mySet.count(k - root->val)) {
            return true;
        } else {
            mySet.insert(root->val);
        }
        return find(root->left, k) || find(root->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return find(root, k);
    }
};
// @lc code=end

