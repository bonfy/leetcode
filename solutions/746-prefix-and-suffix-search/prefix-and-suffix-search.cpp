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
        for (int z = 0; z < words.size(); z++) {
            auto w = words[z];
            for (int i = 0; i <= w.size(); i++) {
                for (int j = 0; j <= w.size(); j++) {
                    weight[w.substr(0, i) + "#" + w.substr(j)] = z;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if (weight.count(prefix + "#" + suffix)) {
            return weight[prefix + "#" + suffix];
        }
        return -1;
    }
    unordered_map<string, int> weight;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
