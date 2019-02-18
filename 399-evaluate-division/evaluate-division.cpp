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
        unordered_map<string, Node*> mp;
        for (int i = 0; i < equations.size(); i++) {
            auto s1 = equations[i].first, s2 = equations[i].second;
            if (!mp.count(s1) && !mp.count(s2)) {
                mp[s1] = new Node(values[i]);
                mp[s2] = new Node();
                mp[s1]->parent = mp[s2];
            } else if (!mp.count(s1)) {
                mp[s1] = new Node(values[i] * mp[s2]->v);
                mp[s1]->parent = mp[s2];
            } else if (!mp.count(s2)) {
                mp[s2] = new Node(mp[s1]->v / values[i]);
                mp[s2]->parent = mp[s1];
            } else {
                unionf(mp[s1], mp[s2], values[i], mp);
            }
        }
        vector<double> ans;
        for (auto p: queries) {
            if (!mp.count(p.first) || !mp.count(p.second) || findp(mp[p.first]) != findp(mp[p.second])) {
                ans.emplace_back(-1);
            } else {
                ans.emplace_back(mp[p.first]->v / mp[p.second]->v);
            }
        }
        return ans;
    }
    struct Node {
        double v;
        Node* parent;
        Node(double a = 1.0): v(a) {parent = this;};
    };
    void unionf(Node* a, Node* b, double num, unordered_map<string, Node*>& mp) {
        auto pa = findp(a);
        auto pb = findp(b);
        auto ratio = b->v * num / pa->v;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (findp(it->second) == pa) {
                it->second->v *= ratio;
            }
        }
        pa->parent = pb;
    }
    Node* findp(Node* node) {
        if (node->parent == node) {
            return node;
        }
        node->parent = findp(node->parent);
        return node->parent;
    }
};
