// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
//
//
// Example 1:
//
//
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
//
//
//
// Example 2:
//
//
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
//
//
//
// Example 3:
//
//
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
//
//
//
// Example 4:
//
//
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
//
//
// Note:
//
//
// 	1 <= S.length <= 200
// 	1 <= T.length <= 200
// 	S and T only contain lowercase letters and '#' characters.
//
//
// Follow up:
//
//
// 	Can you solve it in O(N) time and O(1) space?
//
//
//
//
//
//


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        int skips = 0, skipt = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    i--;
                    skips++;
                } else if (skips > 0) {
                    skips--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    j--;
                    skipt++;
                } else if (skipt > 0) {
                    skipt--;
                    j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0 && S[i] != T[j]) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};
