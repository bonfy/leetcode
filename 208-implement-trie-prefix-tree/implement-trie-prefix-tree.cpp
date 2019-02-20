// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
//
//
// Note:
//
//
// 	You may assume that all inputs are consist of lowercase letters a-z.
// 	All inputs are guaranteed to be non-empty strings.
//
//


class TrieNode {
public:
    TrieNode(): w(false) {
        v.resize(26, nullptr);
    }
    bool w;
    vector<TrieNode*> v;
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (auto c: word) {
            if (!p->v[c - 'a']) {
                p->v[c - 'a'] = new TrieNode();
            }
            p = p->v[c - 'a'];
        }
        p->w = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = query(word);
        return p && p->w;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = query(prefix);
        return p;
    }
    
    TrieNode* query(string word) {
        auto p = root;
        for (auto c: word) {
            if (!p->v[c - 'a']) {
                return nullptr;
            }
            p = p->v[c - 'a'];
        }
        return p;
    }
    
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
