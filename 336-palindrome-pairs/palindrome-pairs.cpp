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
        for (int i = 0; i < words.size(); ++i) {
            pos[words[i]] = i;
        }
        vector<vector<int>> ans;
        function<bool (string&)> pal = [&](string& s){
            int l = 0, h = s.size() - 1;
            while (l < h) {
                if (s[l] != s[h]) return false;
                l++;
                h--;
            }
            return true;
        };
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                string left(words[i].substr(0, j)), right(words[i].substr(j));
                if (pal(left)) {
                    string t(right.rbegin(), right.rend());
                    if (pos.count(t) && pos[t] != i) {
                        ans.emplace_back(vector<int>{pos[t], i});
                    }
                }
                if (pal(right) && j != words[i].size()) {
                    string t(left.rbegin(), left.rend());
                    if (pos.count(t)) {
                        ans.emplace_back(vector<int>{i, pos[t]});
                    }
                }
            }
        }
        return ans;
    }
};
