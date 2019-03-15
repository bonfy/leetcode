//
// Equations are given in the format A / B = k, where  A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
//
// The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.
//
//
// According to the example above:
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
//
//
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
//


class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = values.size();
        unordered_map<string, string> uf;
        unordered_map<string, double> v;
        
        for (int i = 0; i < n; i++) {
            string a = equations[i].first, b = equations[i].second;
            if (!uf.count(a) && !uf.count(b)) {
                uf[a] = a;
                uf[b] = a;
                v[a] = values[i];
                v[b] = 1.0;
            } else if (!uf.count(a)) {
                uf[a] = ufind(uf, b);
                v[a] = v[b] * values[i];
            } else if (!uf.count(b)) {
                uf[b] = ufind(uf, a);
                v[b] = v[a] / values[i];
            } else {
                string pa = ufind(uf, a);
                string pb = ufind(uf, b);
                double ratio = v[b] * values[i] / v[a];
                for (auto it: v) {
                    if (ufind(uf, it.first) == pa) {
                        v[it.first] *= ratio;
                    }
                }
                uf[pb] = pa;
            }
        }
        vector<double> ans;
        for (auto q: queries) {
            string a = q.first, b = q.second;
            if (!uf.count(a) || !uf.count(b) || ufind(uf, a) != ufind(uf, b)) {
                ans.emplace_back(-1.0);
            } else {
                ans.emplace_back(v[a] / v[b]);
            }
        }
        return ans;
    }
    string ufind(unordered_map<string, string>& uf, string k) {
        if (uf[k] != k) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
};
