/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
private:
    int index;
    vector<int> arr;

    void traversal(TreeNode *root, vector<int> &res) {
        if (!root) return;
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }

    vector<int> nodeTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

public:
    BSTIterator(TreeNode* root): index(0), arr(nodeTraversal(root)) {

    }
    
    int next() {
        return arr[index ++];
    }
    
    bool hasNext() {
        return index < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

