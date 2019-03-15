// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//
//
//
// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//
//
// Example:
//
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
//
// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
//
//
//
// Note:
//
// The matrix is only modifiable by the update function.
// You may assume the number of calls to update and sumRegion function is distributed evenly.
// You may assume that row1 ≤ row2 and col1 ≤ col2.
//
//


class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        vals = matrix;
        m = vals.size();
        if (!m) return;
        n = vals[0].size();
        bit.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                add(i + 1, j + 1, vals[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int d = val - vals[row][col];
        add(row + 1, col + 1, d);
        vals[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2 + 1, col2 + 1) - sum(row2 + 1, col1) - sum(row1, col2 + 1) + sum(row1, col1);
    }
    
    void add(int x, int y, int val) {
        int i = x;
        while (i <= m) {
            int j = y;
            while (j <= n) {
                bit[i][j] += val;
                j += (j & -j);
            }
            i += (i & -i);
        }
    }
    
    int sum(int x, int y) {
        int ans = 0;
        int i = x;
        while (i >= 1) {
            int j = y;
            while (j >= 1) {
                ans += bit[i][j];
                j -= (j & -j);
            }
            i -= (i & -i);
        }
        return ans;
    }
    
    vector<vector<int>> vals, bit;
    int m, n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
