// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
//
// Example 2:
//
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int s = newInterval.start, e = newInterval.end;
        auto iter = intervals.begin();
        vector<Interval> ans;
        for (; iter != intervals.end(); iter++) {
            if (iter->start > e) break;
            else if (iter->end < s) ans.emplace_back(*iter);
            else {
                s = min(iter->start, s);
                e = max(iter->end, e);
            }
        }
        ans.emplace_back(Interval(s, e));
        for (; iter != intervals.end(); iter++) {
            ans.emplace_back(*iter);
        }
        return ans;
    }
};
