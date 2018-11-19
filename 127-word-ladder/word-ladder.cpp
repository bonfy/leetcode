// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time.
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return 0 if there is no such transformation sequence.
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
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
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
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        int dist = 0;
        queue<string> q;
        q.emplace(beginWord);
        while (!q.empty()) {
            int n = q.size();
            dist++;
            for (int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                if (p == endWord) return dist;
                dict.erase(p);
                search(p, dict, q);
            }
        }
        return 0;
    }
    void search(string s, unordered_set<string>& dict, queue<string>& q) {
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (int j = 0; j < 26; j++) {
                s[i] = 'a' + j;
                if (s[i] == c) continue;
                if (dict.count(s)) {
                    dict.erase(s);
                    q.emplace(s);
                }
            }
            s[i] = c;
        }
    }
};
