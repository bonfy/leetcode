// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
//
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
// Could you do this in O(n) runtime?
//
// Example:
//
// Input: [3, 10, 5, 25, 2, 8]
//
// Output: 28
//
// Explanation: The maximum result is 5 ^ 25 = 28.
//
//


class Trie {
public:
    Trie* next[2];
    Trie() {
        memset(next, 0, sizeof(next));
    }
};
class Solution {
public:
    Trie* buildTrie(vector<int>& nums, int n, int& len) {
        while (n) {
            len++;
            n >>= 1;
        }
        Trie* root = new Trie();
        Trie* cur;
        for (int k: nums) {
            cur = root;
            for (int j = len - 1; j >= 0; j--) {
                int aim = (k >> j) & 1;
                if (!cur->next[aim]) {
                    cur->next[aim] = new Trie();
                }
                cur = cur->next[aim];
            }
        }
        return root;
    }
    int search(Trie* root, int n, int len) {
        int ans = 0;
        auto cur = root;
        for (int j = len - 1; j >= 0; j--) {
            int bit = (n>>j) & 1;
            if (cur->next[!bit]) {
                ans <<= 1;
                ans |= 1;
                cur = cur->next[!bit];
            } else {
                ans <<= 1;
                cur = cur->next[bit];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int maxim = 0;
        for (int n: nums) {
            maxim = max(maxim, n);
        }
        int len = 0;
        auto root = buildTrie(nums, maxim, len);
        int ans = 0;
        for (int n: nums) {
            ans = max(ans, search(root, n, len));
        }
        return ans;
    }
};
