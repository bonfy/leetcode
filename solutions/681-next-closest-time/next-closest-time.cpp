// Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
//
// You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
//
// Example 1:
//
// Input: "19:34"
// Output: "19:39"
// Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
//
//
//
// Example 2:
//
// Input: "23:59"
// Output: "22:22"
// Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
//
//


class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> digit{600, 60, 10, 1};
        auto split = time.find(":");
        int cur = stoi(time) * 60 + stoi(time.substr(split + 1));
        string next("0000");
        for (int i = 1, d = 0; i <= 1440 && d < 4; i++) {
            int t = (cur + i) % 1440;
            for (d = 0; d < 4; d++) {
                next[d] = '0' + t / digit[d];
                t %= digit[d];
                if (time.find(next[d]) == string::npos) break;
            }
        }
        return next.substr(0, 2) + ":" + next.substr(2); 
    }
};
