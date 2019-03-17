// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
// Given two integers x and y, calculate the Hamming distance.
//
// Note:
// 0 ≤ x, y < 231.
//
//
// Example:
//
// Input: x = 1, y = 4
//
// Output: 2
//
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
//
// The above arrows point to positions where the corresponding bits are different.
//
//


class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        vector<int> vx;
        vector<int> vy;
        trans2(&vx, x);
        trans2(&vy, y);
        for (int i = 0; i < 32; i++) {
            if (vx[i] != vy[i]) {
                cnt++;
            }
        }
        return cnt;
    }
    
private:
    void trans2(vector<int>* inv, int v) {
        while (v) {
            inv->emplace_back(v % 2);
            v /= 2;
        }
        while (inv->size() < 32) {
            inv->emplace_back(0);
        }
    }
};
