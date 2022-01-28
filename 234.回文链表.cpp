/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            if (arr[left] != arr[right]) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};
// @lc code=end

