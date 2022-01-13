/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    ListNode *getMiddelNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *current = head;
        while (current) {
            ListNode *next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }

    void mergeList(ListNode *head1, ListNode *head2) {
        ListNode *node = new ListNode();
        ListNode *cur = node;
        while (head1 || head2) {
            if (head1) {
                cur->next = head1;
                head1 = head1->next;
                cur = cur->next;
            }
            if (head2) {
                cur->next = head2;
                head2 = head2->next;
                cur = cur->next;
            }
        }
    }

public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *mid = getMiddelNode(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
};
// @lc code=end

