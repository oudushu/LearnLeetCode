/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strArr;
        for (int n : nums) {
            strArr.push_back(to_string(n));
        }
        sort(strArr.begin(), strArr.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        if (strArr.front() == "0") return "0";
        string res;
        for (string str : strArr) {
            res += str;
        }
        return res;

        // sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
        //     long sx = 10, sy = 10;
        //     while (sx <= x) {
        //         sx *= 10;
        //     }
        //     while (sy <= y) {
        //         sy *= 10;
        //     }
        //     return sx * y + x < sy * x + y;
        // });
        // if (nums[0] == 0) return "0";
        // string res;
        // for (auto &num : nums) {
        //     res += to_string(num);
        // }
        // return res;
    }
};
// @lc code=end

