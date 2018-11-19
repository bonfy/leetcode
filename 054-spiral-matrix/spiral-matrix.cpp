// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rb = 0;
        int re = matrix.size() - 1;
        if (re < 0) {
            return vector<int>{};
        }
        int cb = 0;
        int ce = matrix[0].size() - 1;
        if (ce < 0) {
            return vector<int>{};
        }
        vector<int> ans{};
        while (rb <= re && cb <= ce) {
            for (int j = cb; j <= ce; j++) {
                ans.emplace_back(matrix[rb][j]);
            }
            rb++;
            for (int i = rb; i <= re; i++) {
                ans.emplace_back(matrix[i][ce]);
            }
            ce--;
            if (rb <= re) {
                for (int j = ce; j >= cb; j--) {
                    ans.emplace_back(matrix[re][j]);
                }
            }
            re--;
            if (cb <= ce) {
                for (int i = re; i >= rb; i--) {
                    ans.emplace_back(matrix[i][cb]);
                }
            }
            cb++;
        }
        return ans;
    }
};
