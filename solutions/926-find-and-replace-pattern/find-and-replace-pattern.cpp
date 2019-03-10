// You have a list of words and a pattern, and you want to know which words in words matches the pattern.
//
// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//
// (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
//
// Return a list of the words in words that match the given pattern. 
//
// You may return the answer in any order.
//
//  
//
//
// Example 1:
//
//
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
// since a and b map to the same letter.
//
//  
//
// Note:
//
//
// 	1 <= words.length <= 50
// 	1 <= pattern.length = words[i].length <= 20
//
//
//


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        function<string (string&)> s2i = [](string& s){
            unordered_map<char, int> c2i;
            string ans;
            for (int i = 0, j = 0; i < s.size(); ++i) {
                if (!c2i.count(s[i])) {
                    c2i[s[i]] = j++;
                }
                ans += 'a' + c2i[s[i]];
            }
            return ans;
        };
        string p = s2i(pattern);
        vector<string> ans;
        for (auto& w: words) {
            if (p == s2i(w)) {
                ans.emplace_back(w);
            }
        }
        return ans;
    }
};
