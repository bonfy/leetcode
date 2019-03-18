//
// In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
//
// The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added.  The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
//
// The resulting graph is given as a 2D-array of edges.  Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.
//
// Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes.  If there are multiple answers, return the answer that occurs last in the given 2D-array.
// Example 1:
//
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given directed graph will be like this:
//   1
//  / \
// v   v
// 2-->3
//
//
// Example 2:
//
// Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
// Output: [4,1]
// Explanation: The given directed graph will be like this:
// 5 <- 1 -> 2
//      ^    |
//      |    v
//      4 <- 3
//
//
// Note:
// The size of the input 2D-array will be between 3 and 1000.
// Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
//


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> firstVio, secondVio;
        unordered_map<int, int> parent;
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            if (parent.count(v)) {
                firstVio = vector<int>{parent[v], v};
                secondVio = e;
                e[1] = -e[1];
            } else {
                parent[v] = u;
            }
        }
        vector<int> uf(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            uf[i] = i;
        }
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            if (v < 0) {
                e[1] = -e[1];
                continue;
            }
            int pu = ufind(uf, u), pv = ufind(uf, v);
            if (pu == pv) {
                if (!firstVio.empty()) return firstVio;
                return e;
            }
            uf[pu] = min(pu, pv);
            uf[pv] = uf[pu];
        }
        return secondVio;
    }
    int ufind(vector<int>& uf, int k) {
        if (uf[k] != k) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
};
