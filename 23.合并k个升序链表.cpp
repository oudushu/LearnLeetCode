/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
        ListNode *node = new ListNode();
        ListNode *cur = node;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 ?: l2);
        return node->next;
    }

    ListNode *merge(vector<ListNode *> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoList(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
// @lc code=end

