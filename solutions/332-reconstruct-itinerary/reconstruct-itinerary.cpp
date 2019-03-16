// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//
// Note:
//
//
// 	If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// 	All airports are represented by three capital letters (IATA code).
// 	You may assume all tickets form at least one valid itinerary.
//
//
// Example 1:
//
//
// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
//
//
// Example 2:
//
//
// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.
//
//


class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>> trip;
        vector<string> r_ans;
        for (auto p: tickets) {
            trip[p.first].emplace(p.second);
        }
        visit("JFK", trip, r_ans);
        return vector<string>(r_ans.rbegin(), r_ans.rend());
    }
    void visit(string airport, map<string, multiset<string>>& trip, vector<string>& r_ans) {
        while (!trip[airport].empty()) {
            auto next = *trip[airport].begin();
            trip[airport].erase(trip[airport].begin());
            visit(next, trip, r_ans);
        }
        r_ans.emplace_back(airport);
    }
};
