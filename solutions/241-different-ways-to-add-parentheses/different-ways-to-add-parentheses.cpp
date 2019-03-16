// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
// Example 1:
//
//
// Input: "2-1-1"
// Output: [0, 2]
// Explanation: 
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
//
// Example 2:
//
//
// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation: 
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
//


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                auto a1 = diffWaysToCompute(input.substr(0, i));
                auto a2 = diffWaysToCompute(input.substr(i + 1));
                for (auto k: a1) {
                    for (auto j: a2) {
                        if (input[i] == '+') {
                            ans.emplace_back(k + j);
                        } else if (input[i] == '-') {
                            ans.emplace_back(k - j);
                        } else {
                            ans.emplace_back(k * j);
                        }
                    }
                }
            }
        }
        if (ans.empty()) ans.emplace_back(stoi(input));
        return ans;
    }
};
