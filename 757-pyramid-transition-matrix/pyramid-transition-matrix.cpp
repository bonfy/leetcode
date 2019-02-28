//
// We are stacking blocks to form a pyramid.  Each block has a color which is a one letter string, like `'Z'`.
//
// For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`.  We are allowed to place the block there only if `(A, B, C)` is an allowed triple.
//
// We start with a bottom row of bottom, represented as a single string.  We also start with a list of allowed triples allowed.  Each allowed triple is represented as a string of length 3.
//
// Return true if we can build the pyramid all the way to the top, otherwise false.
//
//
// Example 1:
//
// Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
// Output: true
// Explanation:
// We can stack the pyramid like this:
//     A
//    / \
//   D   E
//  / \ / \
// X   Y   Z
//
// This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
//
//
//
// Example 2:
//
// Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
// Output: false
// Explanation:
// We can't stack the pyramid to the top.
// Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
//
//
//
// Note:
//
// bottom will be a string with length in range [2, 8].
// allowed will have length in range [0, 200].
// Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
//
//


class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<char>> third(49);
        for (auto&s : allowed) {
            int idx = (s[0] - 'A') * 7 + (s[1] - 'A');
            third[idx].emplace_back(s[2]);
        }
        // unordered_set<string> invalid;
        function<bool (string&, int, string)> search = [&](string& cur, int pos, string next) {
            if (cur.size() == 1) return true;
            // if (invalid.count(cur)) return false;
            if (pos + 1 == cur.size()) return search(next, 0, "");
            int idx = (cur[pos] - 'A') * 7 + (cur[pos + 1] - 'A');
            for (auto& c: third[idx]) {
                if (search(cur, pos + 1, next + c)) return true;
            }
            // invalid.emplace(cur);
            return false;
        };
        return search(bottom, 0, "");
    }
};
