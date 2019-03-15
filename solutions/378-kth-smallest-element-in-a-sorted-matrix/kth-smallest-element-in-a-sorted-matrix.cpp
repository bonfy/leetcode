// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//
// Example:
//
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
//
// return 13.
//
//
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ n2.


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (!n) return 0;
        int l = matrix[0][0], h = matrix[n - 1][n - 1];
        while (l < h) {
            int m = l + (h - l) / 2;
            int cnt = 0;
            for (int i = 0, j = n - 1; i < n; i++) {
                while (j >= 0 && matrix[i][j] > m) j--;
                cnt += j + 1;
            }
            if (cnt < k) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }
};
