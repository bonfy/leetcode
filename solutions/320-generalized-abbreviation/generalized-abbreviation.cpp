// Write a function to generate the generalized abbreviations of a word. 
//
// Note: The order of the output does not matter.
//
// Example:
//
//
// Input: "word"
// Output:
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//
//
//  
//


class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        generate(word, "", 0, true, ans);
        return ans;
    }
    void generate(string& word, string path, int pos, bool can_use_num, vector<string>& ans) {
        if (pos == word.size()) {
            ans.emplace_back(path);
            return;
        }
        generate(word, path + word[pos], pos + 1, true, ans);
        if (can_use_num) {
            for (int len = 1; len + pos <= word.size(); len++) {
                generate(word, path + to_string(len), pos + len, false, ans);
            }
        }
    }
};
