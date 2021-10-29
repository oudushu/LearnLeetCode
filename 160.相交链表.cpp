/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if (!headA || !headB) return nullptr;
        // ListNode *nodeA = headA;
        // while (nodeA) {
        //     ListNode *nodeB = headB;
        //     while (nodeB) {
        //         if (nodeA == nodeB) {
        //             return nodeA;
        //         }
        //         nodeB = nodeB->next;
        //     }
        //     nodeA = nodeA->next;
        // }
        // return nullptr;

        if (!headA || !headB) return nullptr;
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        while (nodeA != nodeB) {
            nodeA = nodeA == nullptr ? headB : nodeA->next;
            nodeB = nodeB == nullptr ? headA : nodeB->next;
        }
        return nodeA;
    }
};
// @lc code=end

