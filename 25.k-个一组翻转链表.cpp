/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
private:
    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = new ListNode();
        node->next = head;
        ListNode *pre = node;
        ListNode *cur = head;
        while (cur) {
            ListNode *tail = pre;
            for (int i = 0; i < k; ++ i) {
                tail = tail->next;
                if (!tail) return node->next;
            }
            ListNode *next = tail->next;
            auto [h, t] = reverse(cur, tail);
            pre->next = h;
            t->next = next;
            pre = t;
            cur = t->next;
        }
        return node->next;
    }
};
// @lc code=end

