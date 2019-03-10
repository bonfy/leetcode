// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in parentheses.
//
// Example 1:
//
//
// Input: numerator = 1, denominator = 2
// Output: "0.5"
//
//
// Example 2:
//
//
// Input: numerator = 2, denominator = 1
// Output: "2"
//
// Example 3:
//
//
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
//
//


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string ans;
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }
        long num = labs(numerator);
        long den = labs(denominator);
        ans += to_string(num / den);
        if (num % den == 0) return ans;
        ans += ".";
        unordered_map<int, int> pos;
        for (long r = num % den; r; r %= den) {
            if (pos.count(r)) {
                ans.insert(pos[r], 1, '(');
                ans += ")";
                break;
            }
            pos[r] = ans.size();
            r *= 10;
            ans += to_string(r / den);
        }
        return ans;
    }
};
