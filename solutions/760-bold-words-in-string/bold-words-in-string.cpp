//
// Given a set of keywords words and a string S, make all appearances of all keywords in S bold.  Any letters between <b> and </b> tags become bold.
//
// The returned string should use the least number of tags possible, and of course the tags should form a valid combination.
//
//
// For example, given that words = ["ab", "bc"] and  S = "aabcd", we should return "a<b>abc</b>d".  Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.
//
//
// Note:
// words has length in range [0, 50].
// words[i] has length in range [1, 10].
// S has length in range [0, 500].
// All characters in words[i] and S are lowercase letters.
//


class Trie {
public:
    vector<Trie*> next;
    bool w;
    Trie(): w(false){
        next.resize(26);
    }
};
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        auto root = new Trie();
        function<void (string&)> build = [&](string& s) {
            auto p = root;
            for (int i = 0; i < s.size(); ++i) {
                if (!p->next[s[i] - 'a']) {
                    p->next[s[i] - 'a'] = new Trie();
                }
                p = p->next[s[i] - 'a'];
            }
            p->w = true;
        };
        for (auto& w: words) {
            build(w);
        }
        vector<int> valid(S.size(), 0);
        for (int i = 0; i < S.size(); ++i) {
            auto p = root;
            function<int (int)> search=[&](int pos) {
                int len = 0;
                for (int i = pos; i < S.size(); ++i) {
                    p = p->next[S[i] - 'a'];
                    if (!p) return len;
                    if (p->w) {len = i - pos + 1;};
                }
                return len;
            };
            int len = search(i);
           
            for (int k = i; k < i + len; ++k) {
                valid[k] = 1;
            }
            
        }
        // for (int i = 0; i < S.size(); ++i) {
        //     cout << valid[i] << " ";
        // }
        // cout << endl;

        string ans;
        int prev = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (prev == 0 and valid[i] == 1) {
                ans += "<b>";
                ans += S[i];
            } else if (prev == 1 and valid[i] == 0) {
                ans += "</b>";
                ans += S[i];
            } else {
                ans += S[i];
            }
            prev = valid[i];
        }
        if (prev) ans += "</b>";
        return ans;
    }
};
