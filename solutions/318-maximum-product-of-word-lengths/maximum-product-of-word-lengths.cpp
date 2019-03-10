// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
// Example 1:
//
//
// Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16 
// Explanation: The two words can be "abcw", "xtfn".
//
// Example 2:
//
//
// Input: ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4 
// Explanation: The two words can be "ab", "cd".
//
// Example 3:
//
//
// Input: ["a","aa","aaa","aaaa"]
// Output: 0 
// Explanation: No such pair of words.
//


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n <= 1) return 0;
        vector<int> bitword(n, 0);
        for (int i = 0; i < n; i++) {
            for (char c: words[i]) {
                bitword[i] |= (1 << (c - 'a'));
            }
        }
        int maxp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(bitword[i] & bitword[j])) {
                    maxp = max(maxp, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return maxp;
    }
};
