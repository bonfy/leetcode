// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
//
// Example:
//
//
// Input: low = "50", high = "100"
// Output: 3 
// Explanation: 69, 88, and 96 are three strobogrammatic numbers.
//
// Note:
// Because the range might be a large number, the low and high numbers are represented as string.
//


class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int nl = low.size(), nh = high.size();
        if (nl > nh) return 0;
        int between = 0;
        for (int i = nl + 1; i < nh; ++i) {
            between += cal(i, i);
        }
        int ans = between;
        ans += count(gen(nl, nl), low, high);
        if (nl < nh) {
            ans += count(gen(nh, nh), low, high);
        }
        return ans;
    }
    unordered_map<int, unordered_map<int, int>> mem;
    int cal(int total, int remain) {
        if (mem.count(total) && mem[total].count(remain)) {
            return mem[total][remain];
        }
        if (remain == 0) return 1;
        if (remain == 1) return 3;
        mem[total][remain] = cal(total, remain - 2) * ((remain == total)? 4: 5);
        return mem[total][remain];
    }
    vector<string> gen(int total, int remain) {
        if (remain == 0) return {""};
        if (remain == 1) return {"0", "1", "8"};
        auto prev = gen(total, remain - 2);
        vector<string> ans;
        for (auto& k: prev) {
            if (total != remain) {
                ans.emplace_back("0" + k + "0");
            }
            ans.emplace_back("1" + k + "1");
            ans.emplace_back("6" + k + "9");
            ans.emplace_back("8" + k + "8");
            ans.emplace_back("9" + k + "6");
        }
        return ans;
    }
    int count(vector<string> str, string l, string h) {
        int ans = 0;
        for (auto& s: str) {
            if (le(l, s) && le(s, h)) {
                ++ans;
            }
        }
        return ans;
    }
    bool le(string a, string b) {
        int na = a.size(), nb = b.size();
        if (na != nb) return na < nb;
        int i = 0;
        while (i < na && a[i] == b[i]) ++i;
        return i == na? true: a[i] < b[i];
    }
};
