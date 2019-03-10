// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//
// Example 1:
//
//
// Input:  "69"
// Output: true
//
//
// Example 2:
//
//
// Input:  "88"
// Output: true
//
// Example 3:
//
//
// Input:  "962"
// Output: false
//


class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        for (int l = 0, h = n - 1; l <= h; ++l, --h) {
            if (image.count(num[l]) && image[num[l]] == num[h]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    unordered_map<char, char> image{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
};
