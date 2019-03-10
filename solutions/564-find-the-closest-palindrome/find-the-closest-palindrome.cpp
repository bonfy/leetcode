// Given an integer n, find the closest integer (not including itself), which is a palindrome. 
//
// The 'closest' is defined as absolute difference minimized between two integers.
//
// Example 1:
//
// Input: "123"
// Output: "121"
//
//
//
// Note:
//
// The input n is a positive integer represented by string, whose length will not exceed 18.
// If there is a tie, return the smaller one as answer.
//
//


class Solution {
public:
    string nearestPalindromic(string n) {
        const int len = n.size();
        set<long> cands;
        long val = stol(n);
        cands.emplace(pow(10, len - 1) - 1);
        cands.emplace(pow(10, len) + 1);
        int r = (len + 1) / 2;
        string ori(n.substr(0, r));
        for (int i = 0; i < 10; ++i) {
            ori.back() = i + '0';
            string r_ori(ori.rbegin(), ori.rend());
            cands.emplace(stol(string(ori + ((len & 1)? r_ori.substr(1): r_ori))));
        }
        cands.erase(val);
        auto x = upper_bound(cands.begin(), cands.end(), val);
        auto y = lower_bound(cands.begin(), cands.end(), val);
        --x;
        auto num = *x;
        if (labs(num - val) > labs(*y - val)) {
            num = *y;
        }
        return to_string(num);
    }
};
