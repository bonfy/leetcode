// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> mp;
        set<vector<int>> st;
        for (int n: nums) {
            mp[n]++;
        }
        for (auto it_a = mp.begin(); it_a != mp.end(); it_a++) {
            for (auto it_b = it_a; it_b != mp.end(); it_b++) {
                int a = it_a->first;
                int b = it_b->first;
                int c = 0 - a - b;
                if (mp.count(c)) {
                    mp[a]--;
                    mp[b]--;
                    mp[c]--;
                    if (mp[a] >= 0 && mp[b] >= 0 && mp[c] >= 0) {
                        vector<int> v{a, b, c};
                        sort(v.begin(), v.end());
                        st.emplace(v);
                    }
                    mp[a]++;
                    mp[b]++;
                    mp[c]++;
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
