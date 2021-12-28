/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        ListNode *node = head;
        int n = 1;
        while (node->next) {
            node = node->next;
            ++ n;
        }
        int add = n - (k % n);
        node->next = head;
        while (add) {
            node = node->next;
            -- add;
        }
        ListNode *res = node->next;
        node->next = nullptr;
        return res;
    }
};
// @lc code=end

