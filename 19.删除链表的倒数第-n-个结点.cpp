/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    int lengthOfList(ListNode *head) {
        int len = 0;
        while (head) {
            len ++;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        int len = lengthOfList(head);
        if (len < n) return head;
        ListNode *node = new ListNode();
        node->next = head;
        ListNode *cur = node;
        for (int i = 0; i < len - n; i ++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return node->next;
    }
};
// @lc code=end

