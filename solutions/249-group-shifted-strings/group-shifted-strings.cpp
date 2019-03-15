// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//
//
// "abc" -> "bcd" -> ... -> "xyz"
//
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
//
// Example:
//
//
// Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
// Output: 
// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
//
//


class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();
        if (!n) return {};
        unordered_map<string, vector<string>> mp;
        for (auto str: strings) {
            string key;
            for (int i = 0; i < str.size() - 1; i++) {
                int dis = str[i + 1] - str[i];
                dis = (dis < 0)? dis + 26: dis;
                char c = 'a' + dis;
                key.insert(key.end(), 1, c);
            }
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto p: mp) {
            sort(p.second.begin(), p.second.end());
            ans.emplace_back(p.second);
        }
        return ans;
    }
};
