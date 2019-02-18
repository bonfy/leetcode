// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
//


class Trie {
public:
    bool w;
    vector<Trie*> v;
    Trie() {
        w = false;
        v.resize(26, nullptr);
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = trie;
        for (auto c: word) {
            if (!p->v[c - 'a']) {
                p->v[c - 'a'] = new Trie();
            }
            p = p->v[c - 'a'];
        }
        p->w = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word, trie);
    }
    bool query(string word, Trie* root) {
        if (!root) return false;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto r: root->v) {
                    if (query(word.substr(i + 1), r)) return true;
                }
                return false;
            } else {
                if (!root->v[c - 'a']) return false;
                root = root->v[c-'a'];
            }
        }
        return root && root->w;
    }
    
    Trie* trie;
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
