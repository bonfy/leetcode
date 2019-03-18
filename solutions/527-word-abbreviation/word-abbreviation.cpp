// Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.
//
//
// Begin with the first character and then the number of characters abbreviated, which followed by the last character.
// If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
//  If the abbreviation doesn't make the word shorter, then keep it as original.
//
//
// Example:
//
// Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
// Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
//
//
//
//
// Note: 
//
//  Both n and the length of each word will not exceed 400.
//  The length of each word is greater than 1.
//  The words consist of lowercase English letters only.
//  The return answers should be in the same order as the original array.
//


class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        if (!n) return {};
        vector<string> ans(n);
        vector<int> pos(n, 1);
        unordered_map<string, vector<int>> dup;
        for (int i = 0; i < n; i++) {
            ans[i] = abbr(dict[i], pos[i]);
            dup[ans[i]].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (dup[ans[i]].size() > 1) {
                auto k = ans[i];
                auto v = dup[ans[i]];
                for (int id: v) {
                    ans[id] = abbr(dict[id], ++pos[id]);
                    dup[ans[id]].emplace_back(id);
                }
                dup.erase(k);
                i--;
            }
        }
        return ans;
    }
    string abbr(string s, int pos) {
        if (s.size() <= 3 || pos == s.size() - 2) return s;
        return s.substr(0, pos) + to_string(s.size() - pos - 1) + s.back();
    }
};
