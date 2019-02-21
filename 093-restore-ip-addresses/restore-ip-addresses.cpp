// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
//
//


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    for (int d = 1; d <= 3; d++) {
                        if (a+b+c+d == s.size()) {
                            auto s1 = s.substr(0, a);
                            auto s2 = s.substr(a, b);
                            auto s3 = s.substr(a+b, c);
                            auto s4 = s.substr(a+b+c, d);
                            int q = stoi(s1);
                            int w = stoi(s2);
                            int e = stoi(s3);
                            int r = stoi(s4);
                            if (q<=255 && w<= 255 && e<= 255 &&r <=255) {
                                q = to_string(q).size();
                                w = to_string(w).size();
                                e = to_string(e).size();
                                r = to_string(r).size();
                                if (q+w+e+r == s.size())
                                ans.emplace_back(s1 +"."+s2+"."+s3+"."+s4);
                            }
                        } 
                    }
                }
            }
        }
        return ans;
    }
};
