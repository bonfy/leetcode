// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Find all strobogrammatic numbers that are of length = n.
//
// Example:
//
//
// Input:  n = 2
// Output: ["11","69","88","96"]
//
//


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return gen(n, n);
    }
    vector<string> gen(int total, int remain) {
        if (remain == 0) return vector<string>{""};
        if (remain == 1) {
            return vector<string>{"0", "1", "8"};
        }
        auto kernel = gen(total, remain - 2);
        vector<string> ans;
        for (auto& k: kernel) {
            if (remain != total) {
                ans.emplace_back("0" + k + "0");
            }
            ans.emplace_back("1" + k + "1");
            ans.emplace_back("6" + k + "9");
            ans.emplace_back("8" + k + "8");
            ans.emplace_back("9" + k + "6");
        }
        return ans;
    }
};
