/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node *, Node *> myMap;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }

        if (myMap.find(node) != myMap.end()) {
            return myMap[node];
        }

        Node *copyNode = new Node(node->val, vector<Node *>());
        myMap[node] = copyNode;

        for (auto &n : node->neighbors) {
            copyNode->neighbors.push_back(cloneGraph(n));
        }

        return copyNode;
    }
};
// @lc code=end

