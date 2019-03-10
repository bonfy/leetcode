// Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//
// Example 1:
//
//
// Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
// Output: true
//
// Example 2:
//
//
// Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
// Output: false
//
// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
//


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> uf(n, 0);
        for (int i = 0; i < n; i++) {
            uf[i] = i;
        }
        for (auto e: edges) {
            int u = e.first;
            int v = e.second;
            int fu = ufind(uf, u);
            int fv = ufind(uf, v);
            if (fu == fv) return false;
            uf[u] = min(fu, fv);
            uf[v] = min(fu, fv);
            n--;
        }
        return n == 1;
    }
    int ufind(vector<int>& uf, int k) {
        if (uf[k] != k) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
};
