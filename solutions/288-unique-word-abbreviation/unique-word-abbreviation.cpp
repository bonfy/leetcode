// An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
//
//
// a) it                      --> it    (no abbreviation)
//
//      1
//      ↓
// b) d|o|g                   --> d1g
//
//               1    1  1
//      1---5----0----5--8
//      ↓   ↓    ↓    ↓  ↓    
// c) i|nternationalizatio|n  --> i18n
//
//               1
//      1---5----0
//      ↓   ↓    ↓
// d) l|ocalizatio|n          --> l10n
//
//
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//
// Example:
//
//
// Given dictionary = [ "deer", "door", "cake", "card" ]
//
// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true
//
//


class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto s: dictionary) {
            if (raw.count(s)) {
                continue;
            }
            raw.emplace(s);
            int n = s.size();
            if (n > 2) s.replace(1, n - 2, to_string(n - 2));
            cnt[s]++;
        }
    }
    
    bool isUnique(string word) {
        int n = word.size();
        string abbr(word);
        if (n > 2) abbr.replace(1, n - 2, to_string(n - 2));
        if (raw.count(word)) {
            return cnt[abbr] == 1;
        } else {
            return cnt[abbr] == 0;
        }
    }
    unordered_set<string> raw;
    unordered_map<string, int> cnt;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
