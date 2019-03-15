// Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.
//
// The returned array must be in sorted order.
//
// Expected time complexity: O(n)
//
//
// Example 1:
//
//
// Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
// Output: [3,9,15,33]
//
//
//
// Example 2:
//
//
// Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
// Output: [-23,-5,1,7]
//
//
//


class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = 0, j = n - 1;
        int idx = (a >= 0) ? n - 1: 0;
        while (i <= j) {
            int va = quad(nums[i], a, b, c);
            int vb = quad(nums[j], a, b, c);
            if (a >= 0) {
                if (va > vb) {
                    ans[idx--] = va;
                    i++;
                } else {
                    ans[idx--] = vb;
                    j--;
                }
            } else {
                if (va < vb) {
                    ans[idx++] = va;
                    i++;
                } else {
                    ans[idx++] = vb;
                    j--;
                }
            }
        }
        return ans;
    }
    inline int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};
