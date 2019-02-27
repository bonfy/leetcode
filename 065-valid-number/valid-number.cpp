// Validate if a given string can be interpreted as a decimal number.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false
//
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:
//
//
// 	Numbers 0-9
// 	Exponent - "e"
// 	Positive/negative sign - "+"/"-"
// 	Decimal point - "."
//
//
// Of course, the context of these characters also matters in the input.
//
// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
//


class Solution {
public:
    bool isNumber(string s) {
        auto spos = s.find_first_not_of(" ");
        if (spos == string::npos) return false;
        auto epos = s.find_last_not_of(" ");
        s = s.substr(spos, epos - spos + 1);
        bool numSaw = false, eSaw = false, pointSaw = false, eNum = true;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                numSaw = true;
                eNum = true;
            } else if (s[i] == '.') {
                if (pointSaw || eSaw) return false;
                pointSaw = true;
            } else if (s[i] == 'e') {
                if (eSaw || !numSaw) return false;
                eSaw = true;
                eNum = false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i && s[i - 1] != 'e') return false;
            } else return false;
        }
        return numSaw && eNum;
    }
};
