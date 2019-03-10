// Let's call an array A a mountain if the following properties hold:
//
//
// 	A.length >= 3
// 	There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
//
//
// Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
//
// Example 1:
//
//
// Input: [0,1,0]
// Output: 1
//
//
//
// Example 2:
//
//
// Input: [0,2,1,0]
// Output: 1
//
//
// Note:
//
//
// 	3 <= A.length <= 10000
// 	0 <= A[i] <= 10^6
// 	A is a mountain, as defined above.
//
//


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, h = A.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (m + 1 < A.size() && A[m] < A[m + 1]) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }
};
