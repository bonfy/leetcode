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
    string solveEquation(string equation) {
        int n = equation.size(), i = 0, coeff = 0, b = 0, sign = 1;
        for (int j = 0; j < n; j++) {
            if (equation[j] == '+' || equation[j] == '-') {
                if (j > i) b += sign*stoi(equation.substr(i, j - i));
                i = j;
            } else if (equation[j] == 'x') {
                if (i == j || equation[j - 1] == '+') {
                    coeff += sign;
                } else if (equation[j - 1] == '-') {
                    coeff -= sign;
                } else {
                    coeff += sign*stoi(equation.substr(i, j - i));
                }
                i = j + 1;
            } else if (equation[j] == '=') {
                if (j > i) b += sign*stoi(equation.substr(i, j - i));
                sign = -1;
                i = j + 1;
            }
        }
        if (i < n) b += sign*stoi(equation.substr(i));
        if (!coeff && !b) return "Infinite solutions";
        if (!coeff) return "No solution";
        int ans = (-b)/coeff;
        return "x=" + to_string(ans);
    }
};
