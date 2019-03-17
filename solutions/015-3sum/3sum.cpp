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
        /*
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, h = n - 1;
            while (l < h) {
                int nl = nums[l], nh = nums[h];
                int sum = nums[i] + nl + nh;
                if (sum == 0) {
                    ans.emplace_back(vector<int>{nums[i], nl, nh});
                    while (l < h && nums[l] == nl) l++;
                    while (l < h && nums[h] == nh) h--;
                } else if (sum < 0) {
                    l++;
                } else {
                    h--;
                }
            }
        }
        return ans;
        */
        /*
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        for (int n: nums) {
            mp[n]++;
        }
        set<vector<int>> st;
        for (auto it_a = mp.begin(); it_a != mp.end(); it_a++) {
            for (auto it_b = it_a; it_b != mp.end(); it_b++) {
                int a = it_a->first;
                int b = it_b->first;
                int c = - a - b;
                if (!mp.count(c)) continue;
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
        return vector<vector<int>>(st.begin(), st.end());
        */
        std::unordered_map<int, int> counts;
        for (const int value : nums) {
          counts[value]++;
        }

        std::vector<std::vector<int>> results;
        std::unordered_set<std::uint64_t> existence;

        for (const int l : nums) {
          for (const int r : nums) {
            // 设三个数为l, m, r
            // 为了"Permutation-去重"，只需要保留l <= m <= r的结果
            const int m = -(l + r);
            if (l > m || m > r) {
              continue;
            }

            // 用于加速计算的pre-check: m存在
            if (!counts.count(m)) continue;

            // 拼接l, r以进行"Identity-去重"
            // 这里为了方便用了uint64_t，也可以用std::pair<int, int>之类的，但需要写一个
            // hash functor以提供给std::unordered_set，稍微麻烦一点
            std::uint64_t code = (static_cast<std::uint64_t>(l) << 32) | r;
            if (existence.count(code)) {
              continue;
            }

            // l, m, r可能是两个或三个相同的数字，我们需要检查counts里对应的数字有那么多个
            auto &lc = counts[l];
            auto &rc = counts[r];
            auto &mc = counts[m];
            --lc; --mc; --rc;

            if (lc >= 0 && mc >= 0 && rc >= 0) {
              results.emplace_back(std::vector<int>({l, m, r}));
              existence.emplace(code);
            }

            ++lc; ++mc; ++rc;
          }
        }

        return results;
    }
};
