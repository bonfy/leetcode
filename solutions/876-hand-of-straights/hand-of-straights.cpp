// Alice has a hand of cards, given as an array of integers.
//
// Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
//
// Return true if and only if she can.
//
//  
//
//
//
//
// Example 1:
//
//
// Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
//
// Example 2:
//
//
// Input: hand = [1,2,3,4,5], W = 4
// Output: false
// Explanation: Alice's hand can't be rearranged into groups of 4.
//
//  
//
// Note:
//
//
// 	1 <= hand.length <= 10000
// 	0 <= hand[i] <= 10^9
// 	1 <= W <= hand.length
//
//


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> cnt;
        for (auto v: hand) {
            cnt[v]++;
        }
        queue<int> q;
        int last = -1, open = 0;
        for (auto v: cnt) {
            int x, y;
            tie(x, y) = v;
            if ((open > 0 && last + 1 < x) || y < open) return false;
            q.emplace(y - open);
            last = x;
            open = y;
            if (q.size() == W) {
                open -= q.front();
                q.pop();
            }
        }
        return open == 0;
    }
};
