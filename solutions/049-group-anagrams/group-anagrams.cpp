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
        unordered_map<string, vector<string>> mp;
        for (auto s: strs) {
            mp[st(s)].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto p: mp) {
            ans.emplace_back(p.second);
        }
        return ans;
    }
    string st(string s) {
        vector<int> dict(26, 0);
        for (char c: s) {
            dict[c - 'a']++;
        }
        string ans;
        for (int i = 0; i < 26; i++) {
            ans.append(dict[i], i + 'a');
        }
        return ans;
    }
};
