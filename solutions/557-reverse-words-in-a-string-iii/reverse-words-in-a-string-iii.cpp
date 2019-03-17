// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
// Example 1:
//
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
//
//
//
// Note:
// In the string, each word is separated by single space and there will not be any extra space in the string.
//


class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        string ns = s;
        int size = s.size();
        for (; j <= size; j++) {
            if (s[j] == ' ' || j == size) {
                reverseTerm(&ns, i, j);
                i = j + 1;
            }
        }
        return move(ns);
    }
    void reverseTerm(string* ns, int i, int j) {
        int e = j - 1;
        while (i < e) {
            swap(ns->at(i++), ns->at(e--));
        }
    }
};
