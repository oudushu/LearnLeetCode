/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* toBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = toBST(nums, left, mid - 1);
        node->right = toBST(nums, mid + 1, right);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

