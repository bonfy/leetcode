// In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
//
// We may rotate the i-th domino, so that A[i] and B[i] swap values.
//
// Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
//
// If it cannot be done, return -1.
//
//  
//
// Example 1:
//
//
//
//
// Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
// Output: 2
// Explanation: 
// The first figure represents the dominoes as given by A and B: before we do any rotations.
// If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
//
//
// Example 2:
//
//
// Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
// Output: -1
// Explanation: 
// In this case, it is not possible to rotate the dominoes to make one row of values equal.
//
//
//  
//
// Note:
//
//
// 	1 <= A[i], B[i] <= 6
// 	2 <= A.length == B.length <= 20000
//
//


class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;
        int imax = 0;
        const int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] != B[i]) {
                ++freq[A[i]];
                ++freq[B[i]];
                if (freq[A[i]] > freq[B[i]]) {
                    if (freq[A[i]] > freq[imax]) {
                        imax = A[i];
                    }
                } else {
                    if (freq[B[i]] > freq[imax]) {
                        imax = B[i];
                    }
                }
            } else {
                ++freq[A[i]];
                if (freq[A[i]] > freq[imax]) {
                    imax = A[i];
                }
            }
        }
        if (freq[imax] != n) return -1;
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == B[i] and A[i] == imax) {
                --a;
                --b;
            }
            if (A[i] == imax) {
                ++a;
            }
            if (B[i] == imax) {
                ++b;
            }
        }
        return min(a, b);
    }
};
