/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *bigHead = new ListNode();
        ListNode *bigCur = bigHead;
        ListNode *smallHead = new ListNode();
        ListNode *smallCur = smallHead;
        while (head) {
            if (head->val >= x) {
                bigCur->next = head;
                bigCur = bigCur->next;
            } else {
                smallCur->next = head;
                smallCur = smallCur->next;
            }
            head = head->next;
        }
        smallCur->next = bigHead->next;
        bigCur->next = nullptr;
        return smallHead->next;
    }
};
// @lc code=end

