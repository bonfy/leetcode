//
// Implement a magic directory with buildDict, and search methods.
//
//
//
// For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.
//
//
//
// For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.
//
//
// Example 1:
//
// Input: buildDict(["hello", "leetcode"]), Output: Null
// Input: search("hello"), Output: False
// Input: search("hhllo"), Output: True
// Input: search("hell"), Output: False
// Input: search("leetcoded"), Output: False
//
//
//
// Note:
//
// You may assume that all the inputs are consist of lowercase letters a-z.
// For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
// Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
//
//


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto w: dict) {
            mem.emplace(w);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if (verified.count(word)) return true;
        if (notin.count(word)) return false;
        for (auto k: mem) {
            if (k.size() == word.size() && changeone(word, k)) {
                verified.emplace(word);
                return true;
            }
        }
        notin.emplace(word);
        return false;
    }
    
    bool changeone(string a, string b) {
        bool change = false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (change) return false;
                change = true;
            }
        }
        return change;
    }
    unordered_set<string> mem;
    unordered_set<string> verified, notin;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
