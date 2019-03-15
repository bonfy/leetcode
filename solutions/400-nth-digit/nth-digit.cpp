// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
//
// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).
//
//
// Example 1:
//
// Input:
// 3
//
// Output:
// 3
//
//
//
// Example 2:
//
// Input:
// 11
//
// Output:
// 0
//
// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
//
//


class Solution {
public:
    int findNthDigit(int n) {
        long base = 9;
        int digit = 1;
        while (n >= base * digit) {
            n -= base * digit;
            base *= 10;
            digit++;
        }
        int index = n % digit;
        if (index == 0) index = digit;
        long v = 1;
        for (int i = 1; i < digit; i++) {
            v *= 10;
        }
        v += (index == digit)? n/digit - 1: n/digit;
        
        for (int i = index; i < digit; i++) {
            v /= 10;
        }
        return v % 10;
    }
};
