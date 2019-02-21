//
// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
//
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.
//
//
//
// Example 1:
//
// Input: "()"
// Output: True
//
//
//
// Example 2:
//
// Input: "(*)"
// Output: True
//
//
//
// Example 3:
//
// Input: "(*))"
// Output: True
//
//
//
// Note:
//
// The string size will be in the range [1, 100].
//
//


class Solution {
public:
    bool checkValidString(string s) {
        // let k = #'(' - #')', k in [low, high]
        int low = 0, high = 0;
        for (char& c: s) {
            if (c == '(') {
                ++low;
                ++high;
            } else if (c == ')') {
                --low;
                --high;
            } else if (c == '*') {
                --low;
                ++high;
            }
            if (high < 0) return false;
            low = max(0, low);
        }
        return low == 0;
    }
};
