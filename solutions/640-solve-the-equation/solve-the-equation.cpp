//
// Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.
//
//
//
// If there is no solution for the equation, return "No solution".
//
//
// If there are infinite solutions for the equation, return "Infinite solutions".
//
//
// If there is exactly one solution for the equation, we ensure that the value of x is an integer.
//
//
// Example 1:
//
// Input: "x+5-3+x=6+x-2"
// Output: "x=2"
//
//
//
// Example 2:
//
// Input: "x=x"
// Output: "Infinite solutions"
//
//
//
// Example 3:
//
// Input: "2x=x"
// Output: "x=0"
//
//
//
// Example 4:
//
// Input: "2x+3x-6x=x+2"
// Output: "x=-1"
//
//
//
// Example 5:
//
// Input: "x=x+2"
// Output: "No solution"
//
//


class Solution {
public:
    string solveEquation(string s) {
        int n = s.size(), coeff = 0, b = 0, sign = 1, slow = 0;
        for (int fast = 0; fast < n; fast++) {
            if (s[fast] == '+' || s[fast] == '-') {
                if (slow < fast) b += sign * stoi(s.substr(slow, fast - slow));
                slow = fast;
            } else if (s[fast] == 'x') {
                if (slow == fast || s[fast - 1] == '+') {
                    coeff += sign;
                } else if (s[fast - 1] == '-') {
                    coeff -= sign;
                } else {
                    coeff += sign * stoi(s.substr(slow, fast - slow));
                }
                slow = fast + 1;
            } else if (s[fast] == '=') {
                if (slow < fast) b += sign * stoi(s.substr(slow, fast - slow));
                sign = -1;
                slow = fast + 1;
            }
        }
        if (slow < n) b += sign * stoi(s.substr(slow));
        if (!coeff && !b) return "Infinite solutions";
        if (!coeff) return "No solution";
        int x = -b / coeff;
        return "x=" + to_string(x);
    }
};
