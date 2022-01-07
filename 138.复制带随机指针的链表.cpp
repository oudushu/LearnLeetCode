/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node *, Node *> cache;
        Node *cur = head;
        while (cur) {
            Node *newNode = new Node(cur->val);
            cache[cur] = newNode;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            if (cur->next) {
                cache[cur]->next = cache[cur->next];
            }
            if (cur->random) {
                cache[cur]->random = cache[cur->random];
            }
            cur = cur->next;
        }
        return cache[head];
    }
};
// @lc code=end

