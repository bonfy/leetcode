// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
//
//  
//
//
//  
//
// Example:
//
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
//  
//
// Note:
//
//
// 	You may use one character in the keyboard more than once.
// 	You may assume the input string will only contain letters of alphabet.
//
//


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> v1 = {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
        unordered_set<char> v2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> v3 = {'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
        vector<unordered_set<char>> keyboard {v1, v2, v3};

        char c;
        bool same;
        int i, j, k;
        vector<string> res;
        for (auto word: words) {
            c = (char)tolower(word[0]);
            for (i = 0; i < 3; i++) {
                if (keyboard[i].find(c) != keyboard[i].end()) {
                    k = i;
                }
            }
            same = true;
            for (i = 1; i < word.size(); i++) {
                if (keyboard[k].find((char)tolower(word[i])) == keyboard[k].end()) {
                    same = false;
                    break;
                }
            }
            if (same) {
                res.emplace_back(word);
            }
            
        }
        return move(res);
    }
        
};
