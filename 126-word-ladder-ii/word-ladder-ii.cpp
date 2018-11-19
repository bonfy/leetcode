// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return an empty list if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: []
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        vector<vector<string>> ans;
        queue<vector<string>> q;
        unordered_set<string> to_del;
        q.emplace(vector<string>{beginWord});
        bool found = false;
        while (!q.empty() && !found) {
            int n = q.size();
            for (auto x: to_del) {
                dict.erase(x);
            }
            to_del.clear();
            for (int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                auto s = p.back();
                if (s == endWord) {
                    ans.emplace_back(p);
                    found = true;
                }
                for (int j = 0; j < s.size(); j++) {
                    char c = s[j];
                    for (int k = 0; k < 26; k++) {
                        s[j] = k + 'a';
                        if (s[j] == c) continue;
                        if (dict.count(s)) {
                            to_del.emplace(s);
                            p.emplace_back(s);
                            q.emplace(p);
                            p.pop_back();
                        }
                    }
                    s[j] = c;
                }
            }
        }
        return ans;
    }
};
