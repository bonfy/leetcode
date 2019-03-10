// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
// Example 1:
//
//
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
//
// Example 2:
//
//
// Input: [[7,10],[2,4]]
// Output: 1
//


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for (auto itv: intervals) {
            start.emplace_back(itv.start);
            end.emplace_back(itv.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int j = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] < end[j]) {
                cnt++;
            } else if (j < n) {
                j++;
            }
        }
        return cnt;
    }
};
