// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//
// Example 1:
//
//
// Input:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
//
// Output: "wertf"
//
//
// Example 2:
//
//
// Input:
// [
//   "z",
//   "x"
// ]
//
// Output: "zx"
//
//
// Example 3:
//
//
// Input:
// [
//   "z",
//   "x",
//   "z"
// ] 
//
// Output: "" 
//
// Explanation: The order is invalid, so return "".
//
//
// Note:
//
//
// 	You may assume all letters are in lowercase.
// 	You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// 	If the order is invalid, return an empty string.
// 	There may be multiple valid order of letters, return any one of them is fine.
//
//


class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> pre, suc;
        unordered_set<char> letters;
        string last;
        for (int i = 0; i < words.size(); ++i) {
            letters.insert(words[i].begin(), words[i].end());
            int len = min(last.size(), words[i].size());
            for (int j = 0; j < len; ++j) {
                if (last[j] != words[i][j]) {
                    suc[last[j]].emplace(words[i][j]);
                    pre[words[i][j]].emplace(last[j]);
                    break;
                }
            }
            last = words[i];
        }
        set<char> nopre(letters.begin(), letters.end()), next;
        for (auto& it: pre) {
            nopre.erase(it.first);
        }
        string ans;
        while (!nopre.empty()) {
            for (int k = nopre.size(); k > 0; --k) {
                char u = *(nopre.begin());
                nopre.erase(u);
                ans += u;
                for (auto& v: suc[u]) {
                    if (!pre.count(v)) continue;
                    pre[v].erase(u);
                    if (pre[v].empty()) {
                        pre.erase(v);
                        next.emplace(v);
                    }
                }
            }
            swap(next, nopre);
            next.clear();
        }
        return ans.size() == letters.size()? ans: "";
    }
};
