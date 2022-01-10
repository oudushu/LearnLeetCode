/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator;
        long denominatorLong = denominator;
        if (numeratorLong % denominatorLong == 0) {
            return to_string(numeratorLong / denominatorLong);
        }

        string ans;
        if ((numeratorLong < 0) ^ (denominatorLong < 0)) {
            ans += '-';
        }

        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        long intPart = numeratorLong / denominatorLong;
        ans += to_string(intPart);
        ans += '.';

        string fractionPart;
        map<long, int> remainderIndexMap;
        long remainder = numeratorLong % denominatorLong;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder)) {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            index ++;
        }

        if (remainder != 0) {
            int index = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0, index) + '(' + fractionPart.substr(index) + ')';
        }

        ans += fractionPart;
        return ans;
    }
};
// @lc code=end

