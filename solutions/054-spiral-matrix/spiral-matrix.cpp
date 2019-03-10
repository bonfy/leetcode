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
        int re = matrix.size() - 1;
        if (re < 0) return {};
        int ce = matrix[0].size() - 1;
        if (ce < 0) return {};
        int rs = 0, cs = 0;
        vector<int> ans;
        while (rs <= re && cs <= ce) {
            for (int j = cs; j <= ce; j++) {
                ans.emplace_back(matrix[rs][j]);
            }
            rs++;
            for (int i = rs; i <= re; i++) {
                ans.emplace_back(matrix[i][ce]);
            }
            ce--;
            if (rs <= re){
            for (int j = ce; j >= cs; j--) {
                ans.emplace_back(matrix[re][j]);
            }
            re--;}
            if (cs <= ce) {
            for (int i = re; i >= rs; i--) {
                ans.emplace_back(matrix[i][cs]);
            }
            cs++;
            }
        }
        return ans;
    }
};
