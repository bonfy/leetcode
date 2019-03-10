//
// Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.
//
// A subsequence of a string S is obtained by deleting 0 or more characters from S.
//
// A sequence is palindromic if it is equal to the sequence reversed.
//
// Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.
//
//
// Example 1:
//
// Input: 
// S = 'bccb'
// Output: 6
// Explanation: 
// The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
// Note that 'bcb' is counted only once, even though it occurs twice.
//
//
//
// Example 2:
//
// Input: 
// S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
// Output: 104860361
// Explanation: 
// There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
//
//
//
// Note:
// The length of S will be in the range [1, 1000].
// Each character S[i] will be in the set {'a', 'b', 'c', 'd'}.
//


class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int base = 1000000007;
        int n = S.size();
        int cnt[3][n][4];
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                for (int x = 0; x < 4; x++) {
                    char c = x + 'a';
                    if (len == 1) cnt[2][i][x] = S[i] == c;
                    else {
                        if (S[i] != c) {
                            cnt[2][i][x] = cnt[1][i + 1][x];
                        } else if (S[i + len - 1] != c) {
                            cnt[2][i][x] = cnt[1][i][x];
                        } else {
                            cnt[2][i][x] = 2; // c, cc
                            if (len > 2) {
                                for (int y = 0; y < 4; y++) {
                                    cnt[2][i][x] = (cnt[2][i][x] + cnt[0][i + 1][y]) % base;
                                }
                            }
                        }
                    }
                }
            }
            for (int l = 0; l < 2; l++) {
                for (int i = 0; i < n; i++) {
                    for (int x = 0; x < 4; x++) {
                        cnt[l][i][x] = cnt[l + 1][i][x];
                    }
                }
            }
        }
        int ans = 0;
        for (int x = 0; x < 4; x++) {
            ans = (ans + cnt[2][0][x]) % base;
        }
        return ans;
    }
};
