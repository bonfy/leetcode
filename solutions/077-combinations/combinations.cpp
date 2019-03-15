// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
//


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        dfs(path, result, 1, 0, n, k);
        return result;
    }
    
private: 
    void dfs(vector<int>& path, vector<vector<int>>& result, int start, int cur, int n, int k){
        if (cur == k) result.push_back(path);
        for (auto i = start; i <=n; i++){
            path.push_back(i);
            dfs(path, result, i+1, cur + 1, n, k);
            path.pop_back();
        }
    }
};
