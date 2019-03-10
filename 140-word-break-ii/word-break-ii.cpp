// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
//
//
// Example 2:
//
//
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []
//


class Solution {
    unordered_map<string, vector<string>> mem;
    vector<string> combine(string& word, vector<string> prev) {
        for (int i = 0; i < prev.size(); i++) {
            prev[i] += " " + word;
        }
        return prev;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (mem.count(s)) return mem[s];
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        if (dict.count(s)) ans.emplace_back(s);
        for (int i = 1; i < s.size(); i++) {
            string suffix = s.substr(i);
            if (dict.count(suffix)) {
                string prefix = s.substr(0, i);
                vector<string> prev = combine(suffix, wordBreak(prefix, wordDict));
                ans.insert(ans.end(), prev.begin(), prev.end());
            }
        }
        mem[s] = ans;
        return ans;
    }
};
