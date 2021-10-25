/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()) {
            int size = myQueue.size();
            Node* pre = nullptr;
            for (int i = 0; i < size; i ++) {
                Node *n = myQueue.front();
                myQueue.pop();
                if (pre) {
                    pre->next = n;
                }
                pre = n;
                if (n->left) {
                    myQueue.push(n->left);
                }
                if (n->right) {
                    myQueue.push(n->right);
                }
            }
        }
        return root;
    }
};
// @lc code=end

