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
        if (intervals.empty()) return 0;
        auto less_s = [&](const Interval& a, const Interval& b){
            return a.start < b.start;
        };
        auto great_e = [&](const Interval& a, const Interval& b){
            return a.end > b.end;
        };
        sort(intervals.begin(), intervals.end(), less_s);
        priority_queue<Interval, vector<Interval>, decltype(great_e)> min_rooms(great_e);
        min_rooms.emplace(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            auto cur = min_rooms.top();
            min_rooms.pop();
            if (intervals[i].start < cur.end) {
                min_rooms.emplace(intervals[i]);
            } else {
                cur.end = max(cur.end, intervals[i].end);
            }
            min_rooms.emplace(cur);
        }
        return min_rooms.size();
    }
};
