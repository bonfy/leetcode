// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int s = digits.size();
        int ah = 0;
        int bitsum = 0;
        digits[s - 1] += 1;
        for (int i = s - 1; i >= 0; i--) {
            bitsum = (ah + digits[i]);
            ah = bitsum / 10;
            digits[i] = bitsum % 10;
        }
        if (ah) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
