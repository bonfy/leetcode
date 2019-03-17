// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//
// Note:
//
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
//
//
//
//
// Example 1:
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//
//
//
// Example 2:
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//
//
//
// Example 3:
//
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
//
//


class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";
        int len = num.size() - k;
        vector<char> stack;
        stack.emplace_back(num[0]);
        for (int i = 1; i < num.size(); i++) {
            while (!stack.empty() && stack.back() > num[i] && k > 0) {
                stack.pop_back();
                k--;
            }
            stack.emplace_back(num[i]);
        }
        vector<char> candi(stack.begin(), stack.begin() + len);
        int j = 0;
        while (j < candi.size() && candi[j] == '0') {
            j++;
        }
        string ans(candi.begin() + j, candi.end());
        return ans.empty()? "0": ans;
    }
};
