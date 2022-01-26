/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        vector<string> res;
        for (int i = 0; i < size; ++ i) {
            int cur = i;
            while (cur < size - 1 && nums[cur] + 1 == nums[cur + 1]) {
                ++ cur;
            }
            string str = to_string(nums[i]);
            if (cur != i) {
                str = str + "->" + to_string(nums[cur]);
            }
            res.push_back(str);
            i = cur;
        }
        return res;
    }
};
// @lc code=end

