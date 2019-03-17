// Given a positive integer N, return the number of positive integers less than or equal to N that have at least 1 repeated digit.
//
//  
//
//
// Example 1:
//
//
// Input: 20
// Output: 1
// Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//
//
//
// Example 2:
//
//
// Input: 100
// Output: 10
// Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//
//
//
// Example 3:
//
//
// Input: 1000
// Output: 262
//
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 10^9
//
//
//
//


class Solution {
    int value = 0;
    bool taken[10];
    void rec(long long num, int dig, int N){
        if(num > N) return;
        value += 1;
        for(int x = 0; x < 10; x += 1){
            if(taken[x]) continue;
            if(dig + x == 0) continue;
            taken[x] = true;
            rec(num * 10 + x, dig + 1, N);
            taken[x] = false;
        }
    }
    int all_different(int N){
        rec(0, 0, N);
        return value;
    }
public:
    int numDupDigitsAtMostN(int N) {
        return N - all_different(N) + 1;
    }
};
