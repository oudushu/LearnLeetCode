/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
private:
    int nextVal(int n) {
        int res = 0;
        while (n > 0) {
            int i = n % 10;
            res += i * i;
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        set<int> mySet;
        while (n != 1 && mySet.find(n) == mySet.end()) {
            mySet.insert(n);
            n = nextVal(n);
        }
        return n == 1;
    }
};
// @lc code=end

