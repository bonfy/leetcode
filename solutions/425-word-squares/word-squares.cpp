// Given a set of words (without duplicates), find all word squares you can build from them.
//
// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
//
// For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
//
//
// b a l l
// a r e a
// l e a d
// l a d y
//
//
// Note:
//
// There are at least 1 and at most 1000 words.
// All words will have the exact same length.
// Word length is at least 1 and at most 5.
// Each word contains only lowercase English alphabet a-z.
//
//
//
// Example 1:
//
// Input:
// ["area","lead","wall","lady","ball"]
//
// Output:
// [
//   [ "wall",
//     "area",
//     "lead",
//     "lady"
//   ],
//   [ "ball",
//     "area",
//     "lead",
//     "lady"
//   ]
// ]
//
// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
//
//
//
// Example 2:
//
// Input:
// ["abat","baba","atan","atal"]
//
// Output:
// [
//   [ "baba",
//     "abat",
//     "baba",
//     "atan"
//   ],
//   [ "baba",
//     "abat",
//     "baba",
//     "atal"
//   ]
// ]
//
// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
//
//


class Solution {
public:
    class TrieNode {
    public:
        vector<int> index;
        vector<TrieNode*> next;
        TrieNode () {
            next.resize(26, nullptr);
        }
    };
    TrieNode* build(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode* t = root;
            for (char c: words[i]) {
                if (!t->next[c - 'a']) {
                    t->next[c - 'a'] = new TrieNode();
                }
                t = t->next[c - 'a'];
                t->index.emplace_back(i);
            }
        }
        return root;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return {};
        vector<vector<string>> ans;
        vector<string> path;
        TrieNode* root = build(words);
        for (auto word: words) {
            path.emplace_back(word);
            backtrack(words, root, 1, path, ans);
            path.pop_back();
        }
        return ans;
    }
    void backtrack(vector<string>& words, TrieNode* root, int level, vector<string>& path, vector<vector<string>>& ans) {
        if (level == words[0].size()) {
            ans.emplace_back(path);
            return;
        }
        string prefix("");
        for (int i = 0; i < level; i++) {
            prefix += path[i][level];
        }
        TrieNode* t = root;
        for (char c: prefix) {
            if (!t->next[c - 'a']) {
                return;
            }
            t = t->next[c - 'a'];
        }
        for (int k: t->index) {
            path.emplace_back(words[k]);
            backtrack(words, root, level + 1, path, ans);
            path.pop_back();
        }
    }
};
