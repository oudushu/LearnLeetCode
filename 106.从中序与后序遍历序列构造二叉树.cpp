/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    map<int, int> indexMap;
    int rootIndex;

    TreeNode *myBuildTree(vector<int> &inorder, vector<int> &postorder, int inorder_left, int inorder_right) {
        if (inorder_left > inorder_right) return nullptr;

        int rootVal = postorder[rootIndex];
        TreeNode *node = new TreeNode(rootVal);
        rootIndex --;

        int index = indexMap[rootVal];
        node->right = myBuildTree(inorder, postorder, index + 1, inorder_right);
        node->left = myBuildTree(inorder, postorder, inorder_left, index - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        rootIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++ i) {
            indexMap[inorder[i]] = i;
        }
        return myBuildTree(inorder, postorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

