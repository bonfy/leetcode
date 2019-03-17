//
// Given two strings representing two complex numbers.
//
//
// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
//
//
// Example 1:
//
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
//
//
//
// Example 2:
//
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
//
//
//
// Note:
//
// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
//
//


class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib, rr, ir;
        conv2num(a, &ra, &ia);
        conv2num(b, &rb, &ib);
        rr = ra*rb - ia*ib;
        ir = ia*rb + ra*ib;
        string strr, stir, stsym;
        strr = to_string(rr);
        stir = to_string(ir);
        return move(strr + "+" + stir + "i");
    }
    void conv2num(const string& str, int* r, int* i) {
        auto p_plus = str.find("+");
        auto strr = str.substr(0, p_plus);
        auto stri = str.substr(p_plus+1);
        *r = stoi(strr);
        *i = stoi(stri);
    }
};
