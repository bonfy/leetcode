//
// Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.  If there is no future day for which this is possible, put 0 instead.
//
// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
//
//
// Note:
// The length of temperatures will be in the range [1, 30000].
// Each temperature will be an integer in the range [30, 100].
//


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        /*
        stack<int> pos;
        for (int i = n - 1; i >= 0; i--) {
            while (!pos.empty() && temperatures[i] >= temperatures[pos.top()]) {
                pos.pop();
            }
            if (!pos.empty()) {
                ans[i] = pos.top() - i;
            }
            pos.emplace(i);
        }
        return ans;
        */
        vector<int> next(101, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            int warm_idx = INT_MAX;
            for (int t = temperatures[i] + 1; t <= 100; t++) {
                if (next[t] < warm_idx) {
                    warm_idx = next[t];
                }
            }
            ans[i] = warm_idx == INT_MAX? 0: warm_idx - i;
            next[temperatures[i]] = i;
        }
        return ans;
    }
};
