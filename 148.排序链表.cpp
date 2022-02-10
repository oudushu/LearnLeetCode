/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode *mySortList(ListNode *head, ListNode *tail) {
        if (!head) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return merge(mySortList(head, slow), mySortList(slow, tail));
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *node = new ListNode();
        ListNode *cur = node;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return node->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mySortList(head, nullptr);
    }
};

// class Solution {
// private:
//     ListNode *mySortList(ListNode *head, ListNode *tail) {
//         if (!head) return head;
//         if (head->next == tail) {
//             head->next = nullptr;
//             return head;
//         }
//         ListNode *slow = head;
//         ListNode *fast = head;
//         while (fast != tail) {
//             slow = slow->next;
//             fast = fast->next;
//             if (fast != tail) {
//                 fast = fast->next;
//             }
//         }
//         return merge(mySortList(head, slow), mySortList(slow, tail));
//     }

//     ListNode *merge(ListNode *head1, ListNode *head2) {
//         ListNode *node1 = head1;
//         ListNode *node2 = head2;
//         ListNode *tempNode = new ListNode();
//         ListNode *cur = tempNode;
//         while (node1 && node2) {
//             if (node1->val <= node2->val) {
//                 cur->next = node1;
//                 node1 = node1->next;
//             } else {
//                 cur->next = node2;
//                 node2 = node2->next;
//             }
//             cur = cur->next;
//         }
//         if (node1) cur->next = node1;
//         if (node2) cur->next = node2;
//         return tempNode->next;
//     }

// public:
//     ListNode* sortList(ListNode* head) {
//         return mySortList(head, nullptr);
//     }
// };
// @lc code=end

