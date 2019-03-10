// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6
//
//


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        if (!n) return 0;
        vector<int> hist(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    hist[j] += 1;
                } else {
                    hist[j] = 0;
                }
            }
            ans = max(ans, maxHist(hist));
        }
        return ans;
    }
    int maxHist(vector<int>& hist) {
        int n = hist.size();
        vector<int> posL(n, -1), posR(n, n);
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            while (p >= 0 && hist[p] >= hist[i]) p = posL[p];
            posL[i] = p;
        }
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < n && hist[i] <= hist[p]) p = posR[p];
            posR[i] = p;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, hist[i] * (posR[i] - posL[i] - 1));
        }
        return ans;
    }
};
