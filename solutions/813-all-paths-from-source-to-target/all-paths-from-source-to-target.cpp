// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
//
// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
//
//
// Example:
// Input: [[1,2], [3], [3], []] 
// Output: [[0,1,3],[0,2,3]] 
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
//
//
// Note:
//
//
// 	The number of nodes in the graph will be in the range [2, 15].
// 	You can print different paths in any order, but you should keep the order of nodes inside one path.
//
//


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int m = graph.size();
        if (!m) return {};
        vector<vector<int>> ans;
        vector<int> tmp(1, 0);
        queue<vector<int>> q;
        q.emplace(tmp);
        while (!q.empty()) {
            for (int i = 0; i < q.size(); i++) {
                auto vec = q.front();
                q.pop();
                auto v = vec.back();
                if (v == m - 1) {
                    ans.emplace_back(vec);
                } else {
                    for (auto u: graph[v]) {
                        vec.emplace_back(u);
                        q.emplace(vec);
                        vec.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};
