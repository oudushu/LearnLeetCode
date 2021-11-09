/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
private:
    int search(vector<int> &coins, int amount, vector<int> &count) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (count[amount] != 0) return count[amount];
        int res = INT_MAX;
        for (int coin : coins) {
            int val = search(coins, amount - coin, count);
            if (val >= 0 && val < res) {
                res = val + 1;
            } 
        }
        count[amount] = res == INT_MAX ? -1 : res;
        return count[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> count(amount + 1, 0);
        return search(coins, amount, count);
    }
};
// @lc code=end

