/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode *node = new ListNode(0, head);
        ListNode *lastSorted = head;
        ListNode *cur = head->next;

        while (cur) {
            if (lastSorted->val <= cur->val) {
                lastSorted = lastSorted->next;
            } else {
                ListNode *pre = node;
                while (pre->next && pre->next->val <= cur->val) {
                    pre = pre->next;
                }
                lastSorted->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            cur = lastSorted->next;
        }

        return node->next;
    }
};
// @lc code=end

