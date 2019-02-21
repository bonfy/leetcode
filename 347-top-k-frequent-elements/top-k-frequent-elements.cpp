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
        vector<int> uniq;
        for (auto& e: nums) {
            if (++freq[e] == 1) {
                uniq.emplace_back(e);
            }
        }
        auto greater = [&](const int a, const int b){return freq[a] > freq[b];};
        function <int (int, int)> partition = [&](int l, int h){
            int idx = rand() % (h - l + 1) + l;
            swap(uniq[idx], uniq[l]);
            int pivot = uniq[l];
            while (l < h) {
                while (l < h && greater(pivot, uniq[h])) --h;
                if (l < h) swap(uniq[l++], uniq[h]);
                while (l < h && greater(uniq[l], pivot)) ++l;
                if (l < h) swap(uniq[l], uniq[h--]);
            }
            uniq[l] = pivot;
            return l;
        };
        int l = 0, h = uniq.size() - 1;
        while (l < h) {
            int m = partition(l, h);
            if (m == k - 1) {
                break;
            }
            if (m < k - 1) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return vector<int>(uniq.begin(), uniq.begin() + k);
    }
};
