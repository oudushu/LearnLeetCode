/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<Node *> myQueue;
        myQueue.push(root);

        while (!myQueue.empty()) {
            int size = myQueue.size();
            vector<int> arr;
            for (int i = 0; i < size; ++ i) {
                Node *node = myQueue.front();
                myQueue.pop();
                arr.push_back(node->val);
                for (Node *child : node->children) {
                    myQueue.push(child);
                }
            }
            res.push_back(arr);
        }

        return res;
    }
};
// @lc code=end

