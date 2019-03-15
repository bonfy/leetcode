// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, h = n - 1, water = 0, level = 0;
        while (l < h) {
            int lower = height[l] < height[h]? height[l++]: height[h--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};
