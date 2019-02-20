// Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
//
// To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
//
// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
//
// Example 1:
//
//
// Input: [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
//
//
// Example 2:
//
//
// Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
//
//
// Notes:
//
//
// 	1 <= A.length = A[0].length <= 20
// 	0 <= A[i][j] <= 1
//
//


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& v: A) {
            int n = v.size();
            for (int i = 0, j = n - 1; i < j; i++, j--) {
                swap(v[i], v[j]);
                v[i] = 1 - v[i];
                v[j] = 1 - v[j];
            }
            if (n % 2) v[n / 2] = 1 - v[n / 2];
        }
        return A;
    }
};
