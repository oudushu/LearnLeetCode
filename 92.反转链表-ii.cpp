/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// private:
//     ListNode *reverse(ListNode* head) {
//         if (!head) return head;
//         ListNode *pre = nullptr;
//         ListNode *cur = head;
//         while (cur) {
//             ListNode *next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//         return pre;
//     }
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode *leftNode = new ListNode(0, head);
//         ListNode *leftNodePtr = leftNode;
//         for (int i = 1; i < left; i ++) {
//             leftNodePtr = leftNodePtr->next;
//         }

//         ListNode *reverseNodePtr = leftNodePtr;
//         for (int i = left; i <= right; i ++) {
//             reverseNodePtr = reverseNodePtr->next;
//         }

//         ListNode *rightNodePtr = reverseNodePtr->next;
//         reverseNodePtr->next = nullptr;

//         ListNode *reverseNode = leftNodePtr->next;
        
//         leftNodePtr->next = reverse(reverseNode);

//         reverseNode->next = rightNodePtr;

//         return leftNode->next;
//     }
// };

class Solution {
private:
    pair<ListNode *, ListNode *> reverseList(ListNode *head, ListNode *tail) {
        ListNode *pre = tail->next;
        ListNode *cur = head;
        while (pre != tail) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *node = new ListNode(0, head);
        // ListNode *pre = node;
        ListNode *pre = node;
        ListNode *tail = node;
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        for (int i = 0; i < right; ++i) {
            tail = tail->next;
        }
        ListNode *next = tail->next;
        auto[h, t] = reverseList(pre->next, tail);
        pre->next = h;
        t->next = next;
        return node->next;
    }

};


// @lc code=end

