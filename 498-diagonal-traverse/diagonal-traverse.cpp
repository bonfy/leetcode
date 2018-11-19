// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//  
//
// Example:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
//
// Output:  [1,2,4,7,5,3,6,8,9]
//
// Explanation:
//
//
//
//  
//
// Note:
//
// The total number of elements of the given matrix will not exceed 10,000.
//


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return {};
        int n = matrix[0].size();
        if (!n) return {};
        int total = m * n;
        vector<int> ans;
        int i = 0, j = 0, k = 0;
        vector<int> dir{-1, 1, -1};
        while (i * n + j < total) {
            ans.emplace_back(matrix[i][j]);
            i += dir[k];
            j += dir[k + 1];
            if (i >= m) {
                i = m - 1;
                j += 2;
                k = 1 - k;
            }
            if (j >= n) {
                j = n - 1;
                i += 2;
                k = 1 - k;
            }
            if (i < 0) {
                i = 0;
                k = 1 - k;
            }
            if (j < 0) {
                j = 0;
                k = 1 - k;
            }
        }
        return ans;
    }
};
