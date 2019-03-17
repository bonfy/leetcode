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


struct Trie {
    bool w;
    vector<Trie*> next;
    Trie(): w(false) {
        next.resize(26);
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = root;
        for (char& c: word) {
            if (!p->next[c - 'a']) {
                p->next[c - 'a'] = new Trie();
            }
            p = p->next[c - 'a'];
        }
        p->w = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word, 0, root);
    }
    bool query(string& s, int pos, Trie* p) {
        if (pos == s.size() && p) {
            return p->w;
        }
        if (s[pos] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (p->next[i] && query(s, pos + 1, p->next[i])) return true;
            }
            return false;
        } else {
            return p->next[s[pos] - 'a'] && query(s, pos + 1, p->next[s[pos] - 'a']);
        }
    }
    Trie* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
