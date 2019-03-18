// Given many words, words[i] has weight i.
//
// Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.
//
// Examples:
//
//
// Input:
// WordFilter(["apple"])
// WordFilter.f("a", "e") // returns 0
// WordFilter.f("b", "") // returns -1
//
//
//  
//
// Note:
//
//
// 	words has length in range [1, 15000].
// 	For each test case, up to words.length queries WordFilter.f may be made.
// 	words[i] has length in range [1, 10].
// 	prefix, suffix have lengths in range [0, 10].
// 	words[i] and prefix, suffix queries consist of lowercase letters only.
//
//
//  
//


class WordFilter {
public:
    WordFilter(vector<string> words) {
        for (int w = 0; w < words.size(); w++) {
            for (int i = 0; i <= words[w].size(); i++) {
                pre[words[w].substr(0, i)].emplace_back(w);
                suf[words[w].substr(i)].emplace_back(w);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if (!pre.count(prefix) || !suf.count(suffix)) {
            return -1;
        }
        auto p = pre[prefix], s = suf[suffix];
        int i = p.size() - 1, j = s.size() - 1;
        while (i >= 0 && j >= 0) {
            if (p[i] == s[j]) {
                return p[i];
            } else if (p[i] > s[j]) {
                i--;
            } else {
                j--;
            }
        }
        return -1;
    }
    unordered_map<string, vector<int>> pre, suf;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
