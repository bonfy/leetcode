// Write a function that takes a string as input and reverse only the vowels of a string.
//
// Example 1:
//
//
// Input: "hello"
// Output: "holle"
//
//
//
// Example 2:
//
//
// Input: "leetcode"
// Output: "leotcede"
//
//
// Note:
// The vowels does not include the letter "y".
//
//  
//


class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I','O','U'};
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while(i < j && !vowel.count(s[i])) i++;
            while(i < j && !vowel.count(s[j])) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
