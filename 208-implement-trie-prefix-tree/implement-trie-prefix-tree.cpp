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
    bool w;
    vector<TrieNode*> next;
    TrieNode() {
        w = false;
        next.resize(26, nullptr);
    }
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
        for (char c: word) {
            if (!p->next[c - 'a']) {
                p->next[c - 'a'] = new TrieNode();
            }
            p = p->next[c - 'a'];
        }
        p->w = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = query(root, word);
        return p && p->w;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = query(root, prefix);
        return p;
    }
    
    TrieNode* query(TrieNode* r, string s) {
        auto p = r;
        for (char c: s) {
            if (!p->next[c - 'a']) {
                return nullptr;
            }
            p = p->next[c - 'a'];
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
