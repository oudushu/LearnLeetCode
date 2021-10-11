/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return l1;
        if (!l1) return l2;
        if (!l2) return l1;
        int tmp = 0;
        ListNode *head = new ListNode();
        ListNode *node = head;
        while (l1 || l2) {
            int sum = tmp;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            node->next = new ListNode(sum % 10);
            tmp = sum / 10;
            node = node->next;
        }
        if (tmp > 0) {
            node->next = new ListNode(tmp);
        }
        return head->next;
    }
};
// @lc code=end

