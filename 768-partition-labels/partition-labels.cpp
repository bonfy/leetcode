//
// A string S of lowercase letters is given.  We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
//
//
// Example 1:
//
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
//
//
//
// Note:
// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.
//


class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<vector<int>> itv(26, vector<int>{-1, -1});
        for (int i = 0; i < S.size(); i++) {
            if (itv[S[i] - 'a'][0] == -1) {
                itv[S[i] - 'a'][0] = i;
                itv[S[i] - 'a'][1] = i;
            } else {
                itv[S[i] - 'a'][1] = i;
            }
        }
        vector<vector<int>> tmp(itv);
        itv.clear();
        for (auto v: tmp) {
            if (v[0] != -1 && v[1] != -1) {
                itv.emplace_back(v);
            }
        }
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };
        sort(itv.begin(), itv.end(), cmp);
        vector<vector<int>> ans;
        ans.emplace_back(itv[0]);
        for (int i = 1; i < itv.size(); i++) {
            if (ans.back()[1] < itv[i][0]) {
                ans.emplace_back(itv[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], itv[i][1]);
            }
        }
        vector<int> res;
        for (auto v: ans) {
            res.emplace_back(v[1] - v[0] + 1);
        }
        return res;
    }
};
