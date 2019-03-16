//
// You are given a string expression representing a Lisp-like expression to return the integer value of.
//
// The syntax for these expressions is given as follows.
//
// An expression is either an integer, a let-expression, an add-expression, a mult-expression, or an assigned variable.  Expressions always evaluate to a single integer.
//
// (An integer could be positive or negative.)
//
// A let-expression takes the form (let v1 e1 v2 e2 ... vn en expr), where let is always the string "let", then there are 1 or more pairs of alternating variables and expressions, meaning that the first variable v1 is assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, and so on sequentially; and then the value of this let-expression is the value of the expression expr.
//
// An add-expression takes the form (add e1 e2) where add is always the string "add", there are always two expressions e1, e2, and this expression evaluates to the addition of the evaluation of e1 and the evaluation of e2.
//
// A mult-expression takes the form (mult e1 e2) where mult is always the string "mult", there are always two expressions e1, e2, and this expression evaluates to the multiplication of the evaluation of e1 and the evaluation of e2.
//
// For the purposes of this question, we will use a smaller subset of variable names.  A variable starts with a lowercase letter, then zero or more lowercase letters or digits.  Additionally for your convenience, the names "add", "let", or "mult" are protected and will never be used as variable names.
//
// Finally, there is the concept of scope.  When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially.  It is guaranteed that every expression is legal.  Please see the examples for more details on scope.
//
//
// Evaluation Examples:
//
// Input: (add 1 2)
// Output: 3
//
// Input: (mult 3 (add 2 3))
// Output: 15
//
// Input: (let x 2 (mult x 5))
// Output: 10
//
// Input: (let x 2 (mult x (let x 3 y 4 (add x y))))
// Output: 14
// Explanation: In the expression (add x y), when checking for the value of the variable x,
// we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
// Since x = 3 is found first, the value of x is 3.
//
// Input: (let x 3 x 2 x)
// Output: 2
// Explanation: Assignment in let statements is processed sequentially.
//
// Input: (let x 1 y 2 x (add x y) (add x y))
// Output: 5
// Explanation: The first (add x y) evaluates as 3, and is assigned to x.
// The second (add x y) evaluates as 3+2 = 5.
//
// Input: (let x 2 (add (let x 3 (let x 4 x)) x))
// Output: 6
// Explanation: Even though (let x 4 x) has a deeper scope, it is outside the context
// of the final x in the add-expression.  That final x will equal 2.
//
// Input: (let a1 3 b2 (add a1 1) b2) 
// Output 4
// Explanation: Variable names can contain digits after the first character.
//
//
//
// Note:
// The given string expression is well formatted: There are no leading or trailing spaces, there is only a single space separating different components of the string, and no space between adjacent parentheses.  The expression is guaranteed to be legal and evaluate to an integer.
// The length of expression is at most 2000.  (It is also non-empty, as that would not be a legal expression.)
// The answer and all intermediate calculations of that answer are guaranteed to fit in a 32-bit integer.
//


class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> vals;
        return eval(expression, vals);
    }
    int eval(string exp, unordered_map<string, int> vals) {
        if (exp.empty()) {
            return 0;
        }
        if (isdigit(exp[0]) || exp[0] == '-') {
            return stoi(exp);
        } else if (isalpha(exp[0])) {
            return vals[exp];
        }
        exp = exp.substr(1, exp.size() - 2);
        int idx = 0;
        string action = parse(exp, idx);
        if (action == "let") {
            while (true) {
                string x = parse(exp, idx);
                if (idx >= exp.size()) {
                    return eval(x, vals);
                }
                vals[x] = eval(parse(exp, idx), vals);
            }
        } else if (action == "add") {
            return eval(parse(exp, idx), vals) + eval(parse(exp, idx), vals);
        } else if (action == "mult") {
            return eval(parse(exp, idx), vals) * eval(parse(exp, idx), vals);
        }
    }
    string parse(string s, int& idx) {
        int i = idx, j = idx + 1, stk = 1;
        if (s[i] == '(') {
            while (stk != 0) {
                if (s[j] == ')') {
                    stk--;
                } else if (s[j] == '(') {
                    stk++;
                }
                j++;
            }
        } else {
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
        }
        idx = j + 1;
        return s.substr(i, j - i);
    }
};
