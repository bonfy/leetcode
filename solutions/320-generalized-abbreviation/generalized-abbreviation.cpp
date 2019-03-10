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
        function<void (int, string, bool)> generate=[&](int pos, string path, bool canNum){
            if (pos == word.size()) {
                ans.emplace_back(path);
            } else {
                generate(pos + 1, path + word[pos], true);
                if (canNum) {
                    for (int len = 1; pos + len <= word.size(); ++len) {
                        generate(pos + len, path + to_string(len), false);
                    }
                }
            }
        };
        generate(0, "", true);
        return ans;
    }
};
