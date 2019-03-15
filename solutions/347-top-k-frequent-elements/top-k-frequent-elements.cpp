// Given a non-empty array of integers, return the k most frequent elements.
//
// Example 1:
//
//
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
//
//
//
// Example 2:
//
//
// Input: nums = [1], k = 1
// Output: [1]
//
//
// Note: 
//
//
// 	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// 	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//
//


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n: nums) {
            freq[n]++;
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_pq(cmp);
        for (pair<int, int> p: freq) {
            if (min_pq.size() >= k) {
                if (min_pq.top().second < p.second) {
                    min_pq.pop();
                    min_pq.emplace(p);
                }
            } else {
                min_pq.emplace(p);
            }
        }
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = min_pq.top().first;
            min_pq.pop();
        }
        return ans;
    }
};
