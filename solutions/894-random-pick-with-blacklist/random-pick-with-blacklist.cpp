// Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.
//
// Optimize it such that it minimizes the call to system’s Math.random().
//
// Note:
//
//
// 	1 <= N <= 1000000000
// 	0 <= B.length < min(100000, N)
// 	[0, N) does NOT include N. See interval notation.
//
//
// Example 1:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[1,[]],[],[],[]]
// Output: [null,0,0,0]
//
//
// Example 2:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[2,[]],[],[],[]]
// Output: [null,1,1,1]
//
//
// Example 3:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[3,[1]],[],[],[]]
// Output: [null,0,0,2]
//
//
// Example 4:
//
//
// Input: 
// ["Solution","pick","pick","pick"]
// [[4,[2]],[],[],[]]
// Output: [null,1,3,1]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.
//


class Solution {
public:
    Solution(int N, vector<int> blacklist):n(N) {
        for (auto b: blacklist) {
            black_map[b] = -1;
        }
        m = N - black_map.size();
        int ex = N;
        for (auto b: blacklist) {
            if (b < m) {
                while (black_map.count(ex - 1)) {
                    ex -= 1;
                }
                black_map[b] = --ex;
            }
        }
    }
    
    int pick() {
        int f = rand() % m;
        if (black_map.count(f)) {
            return black_map[f];
        }
        return f;
    }
    unordered_map<int, int> black_map;
    int m, n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
