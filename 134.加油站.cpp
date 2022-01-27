/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int i = 0;
        while (i < size) {
            int sumOfCost = 0, sumOfGas = 0;
            int count = 0;
            while (count < size) {
                int j = (i + count) % size;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                count ++;
            }
            if (count == size) {
                return i;
            } else {
                i = i + count + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

