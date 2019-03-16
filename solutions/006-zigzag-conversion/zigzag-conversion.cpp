// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
//
// Example 2:
//
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows < 2) {
            return s;
        }
        int period = 2 * numRows - 2;
        string result;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.size(); j += period) {
                result += s[j];
                
                if (i > 0 && i < numRows - 1) {
                    int t = j + period - 2*i;
                    if (t < s.size()) {
                        result += s[t];
                    }
                }
            }
        }
        return result;
    }
};
