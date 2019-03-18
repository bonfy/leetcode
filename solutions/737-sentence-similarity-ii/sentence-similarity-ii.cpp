// Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.
//
// For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].
//
// Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.
//
// Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.
//
// Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
//
// Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
//
// Note:
//
//
// 	The length of words1 and words2 will not exceed 1000.
// 	The length of pairs will not exceed 2000.
// 	The length of each pairs[i] will be 2.
// 	The length of each words[i] and pairs[i][j] will be in the range [1, 20].
//
//
//  
//


class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int n = words1.size();
        if (words2.size() != n) return false;
        unordered_map<string, string> parent;
        for (auto p: pairs) {
            if (!parent.count(p.first)) {
                parent[p.first] = p.first;
            }
            string fa = ufind(parent, p.first);
            if (!parent.count(p.second)) {
                parent[p.second] = fa;
            } else {
                string fb = ufind(parent, p.second);
                parent[fb] = fa;
            }
        }
        for (int i = 0; i < n; i++) {
            auto p1 = ufind(parent, words1[i]);
            auto p2 = ufind(parent, words2[i]);
            if (p1 != p2) return false;
        }
        return true;
    }
    string& ufind(unordered_map<string, string>& parent, string& key) {
        if (parent[key] != key) {
            parent[key] = ufind(parent, parent[key]);
        }
        return parent[key];
    }
};
