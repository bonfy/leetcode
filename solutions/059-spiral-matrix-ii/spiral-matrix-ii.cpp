// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        if (!n) {
            return ans;
        }
        int num = 1;
        int rb = 0;
        int cb = 0;
        int re = n - 1;
        int ce = n - 1;
        while (rb <= re && cb <= ce) {
            for (int j = cb; j <= ce; j++) {
                ans[rb][j] = num++;
            }
            rb++;
            for (int i = rb; i <= re; i++) {
                ans[i][ce] = num++;
            }
            ce--;
            for (int j = ce; j >= cb; j--) {
                if (rb <= re) {
                    ans[re][j] = num++;
                }
            }
            re--;
            for (int i = re; i >= rb; i--) {
                if(cb <= ce) {
                    ans[i][cb] = num++;
                }
            }
            cb++;
        }
        return ans;
    }
};
