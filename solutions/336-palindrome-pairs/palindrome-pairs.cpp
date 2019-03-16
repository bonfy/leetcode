// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
//
// Example 1:
//
//
//
// Input: ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]] 
// Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
//
//
//
// Example 2:
//
//
// Input: ["bat","tab","cat"]
// Output: [[0,1],[1,0]] 
// Explanation: The palindromes are ["battab","tabbat"]
//
//
//


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> pos;
        for (int i = 0; i < words.size(); i++) {
            pos[words[i]] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                auto left = words[i].substr(0, j);
                auto right = words[i].substr(j);
                if (pal(left)) {
                    string r(right.rbegin(), right.rend());
                    if (pos.count(r) && pos[r] != i) {
                        ans.emplace_back(vector<int>({pos[r], i}));
                    }
                }
                if (!right.empty() && pal(right)) {
                    string r(left.rbegin(), left.rend());
                    if (pos.count(r) && pos[r] != i) {
                        ans.emplace_back(vector<int>({i, pos[r]}));
                    }
                }
            }
        }
        return ans;
    }
    bool pal(string s) {
        for (int l = 0, h = s.size() - 1; l < h; l++, h--) {
            if (s[l] != s[h]) return false;
        }
        return true;
    }
};
