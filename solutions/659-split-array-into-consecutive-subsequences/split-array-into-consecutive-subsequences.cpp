// You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
//
// Example 1:
//
// Input: [1,2,3,3,4,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3
// 3, 4, 5
//
//
//
// Example 2:
//
// Input: [1,2,3,3,4,4,5,5]
// Output: True
// Explanation:
// You can split them into two consecutive subsequences : 
// 1, 2, 3, 4, 5
// 3, 4, 5
//
//
//
// Example 3:
//
// Input: [1,2,3,4,4,5]
// Output: False
//
//
//
// Note:
//
// The length of the input is in range of [1, 10000]
//
//


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, potential_seqnum_startwith;
        for (int e: nums) {
            freq[e]++;
        }
        for (int e: nums) {
            if (freq[e] == 0) continue;
            if (potential_seqnum_startwith[e] > 0) {
                potential_seqnum_startwith[e]--;
                potential_seqnum_startwith[e + 1]++;
            } else if (freq[e + 1] > 0 && freq[e + 2] > 0) {
                freq[e + 1]--;
                freq[e + 2]--;
                potential_seqnum_startwith[e + 3]++;
            } else {
                return false;
            }
            freq[e]--;
        }
        return true;
    }
};
