// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces  . The integer division should truncate toward zero.
//
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].
//
// Some examples:
//
//
// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
//
//
//  
//
// Note: Do not use the eval built-in library function.
//


class Solution {
public:
    int calculate(string s) {
        auto pos = s.find_first_not_of(' ');
        if (pos == string::npos) return 0;
        s = s.substr(pos);
        if (s[0] == '-') s.insert(s.begin(), 1, '0');
        while (s.find("(-") != string::npos) {
            auto p = s.find("(-");
            s.insert(s.begin() + p + 1, 1, '0');
        }
        stack<long> nums;
        stack<char> sym;
        function<void ()> cal = [&](){
            auto left = nums.top();
            nums.pop();
            auto& right = nums.top();
            auto opr = sym.top();
            sym.pop();
            if (opr == '+') {
                right += left;
            } else if (opr == '-') {
                right = left - right;
            } else if (opr == '*') {
                right *= left;
            } else if (opr == '/') {
                right = left / right;
            }
        };
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int j = i;
                while (i >= 0 and isdigit(s[i])) --i;
                ++i;
                nums.emplace(stol(s.substr(i, j - i + 1)));
            } else {
                if (s[i] == '*' || s[i] == '/' || s[i] == ')') {
                    sym.emplace(s[i]);
                } else if (s[i] == '+' || s[i] == '-') {
                    while (sym.size() && (sym.top() == '*' || sym.top() == '/')) {
                        cal();
                    }
                    sym.emplace(s[i]);
                } else if (s[i] == '(') {
                    while (sym.size() && sym.top() != ')') {
                        cal();
                    }
                    sym.pop();
                }
            }
        }
        while (sym.size()) {
            cal();
        }
        return nums.empty()? 0: nums.top();
    }
};
