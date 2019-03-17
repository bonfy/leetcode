// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anas;
        for (auto s: strs) {
            anas[mysort(s)].emplace_back(s);
        }
        for (auto p: anas) {
            ans.emplace_back(p.second);
        }
        return ans;
    }
    string mysort(string s) {
        vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c - 'a']++;
        }
        string ans;
        for (int i = 0; i < 26; i++) {
            ans.append(cnt[i], i + 'a');
        }
        return ans;
    }
};
