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
        int d = 1;
        queue<string> q;
        q.emplace(beginWord);
        while (q.size()) {
            ++d;
            for (int t = q.size(); t > 0; --t) {
                auto p = q.front();
                q.pop();
                for (int i = 0; i < p.size(); ++i) {
                    char c = p[i];
                    for (int j = 0; j < 26; ++j) {
                        if (j + 'a' == c) continue;
                        p[i] = j + 'a';
                        if (p == endWord) return d;
                        if (dict.count(p)) {
                            q.emplace(p);
                            dict.erase(p);
                        }
                    }
                    p[i] = c;
                }
            }
        }
        return 0;
    }
};
