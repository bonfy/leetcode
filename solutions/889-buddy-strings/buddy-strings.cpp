// Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
//
//  
//
// Example 1:
//
//
//
// Input: A = "ab", B = "ba"
// Output: true
//
//
//
// Example 2:
//
//
// Input: A = "ab", B = "ab"
// Output: false
//
//
//
// Example 3:
//
//
// Input: A = "aa", B = "aa"
// Output: true
//
//
//
// Example 4:
//
//
// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
//
//
//
// Example 5:
//
//
// Input: A = "", B = "aa"
// Output: false
//
//
//  
//
// Note:
//
//
// 	0 <= A.length <= 20000
// 	0 <= B.length <= 20000
// 	A and B consist only of lowercase letters.
//
//
//
//
//
//
//


class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A == B && unordered_set<char>(A.begin(), A.end()).size() < A.size()) return true;
        vector<int> dif;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                dif.emplace_back(i);
            }
        }
        if (dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]]) return true;
        return false;
    }
};
