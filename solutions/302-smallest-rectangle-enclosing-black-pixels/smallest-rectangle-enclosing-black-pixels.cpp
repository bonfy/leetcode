// An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
//
// Example:
//
//
// Input:
// [
//   "0010",
//   "0110",
//   "0100"
// ]
// and x = 0, y = 2
//
// Output: 6
//
//


class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        if (!m) return 0;
        int n = image[0].size();
        int left = search(image, 0, y, 0, m, 0, 1);
        int right = search(image, y + 1, n, 0, m, 0, 0);
        int top = search(image, 0, x, left, right, 1, 1);
        int down = search(image, x + 1, m, left, right, 1, 0);
        return (down - top) * (right - left);
    }
    int search(vector<vector<char>>& image, int l, int h, int lb, int ub, int forrow, int for1) {
        while (l < h) {
            int m = l + (h - l) / 2;
            if (sat(image, m, lb, ub, forrow, for1)) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    bool sat(vector<vector<char>>& image, int m, int lb, int ub, int forrow, int for1) {
        int k = lb;
        while (k < ub && (forrow? (image[m][k] == '0'): (image[k][m] == '0'))) {
            k++;
        }
        return k < ub == for1;
    }
};
