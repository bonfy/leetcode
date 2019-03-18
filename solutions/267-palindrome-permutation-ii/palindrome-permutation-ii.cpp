// Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
//
// Example 1:
//
//
// Input: "aabb"
// Output: ["abba", "baab"]
//
// Example 2:
//
//
// Input: "abc"
// Output: []
//


class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ans;
        n = s.size();
        unordered_map<char, int> dict;
        int single = 0;
        for (char& c: s) {
            if (++dict[c] & 1) ++single;
            else --single;
        }
        if (single >= 2) return ans;
        gen(dict, "", "", ans);
        return ans;
    }
    void gen(unordered_map<char, int> dict, string l, string r, vector<string>& ans) {
        if (dict.size() == 1) {
            char c = dict.begin()->first;
                ans.emplace_back(l + string(dict[c], c) + r);
            return;
        }
        for (auto it: dict) {
            if (it.second == 1) continue;
            char c = it.first;
            int freq = it.second;
            auto tdict = dict;
            tdict[c] = freq - 2;
            if (tdict[c] == 0)
                tdict.erase(c);
            gen(tdict, l + string(1, c), string(1, c) + r, ans);
            // dict[c] = freq;
        }
    }
    int n;
};
