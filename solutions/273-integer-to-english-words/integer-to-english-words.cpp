// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
//
// Example 1:
//
//
// Input: 123
// Output: "One Hundred Twenty Three"
//
//
// Example 2:
//
//
// Input: 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
//
// Example 3:
//
//
// Input: 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//
//
// Example 4:
//
//
// Input: 1234567891
// Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
//
//


class Solution {
public:
    string numberToWords(int num) {
        if (!num) return "Zero";
        string ans;
        int k = 0;
        while (num) {
            if (num % 1000) {
                ans = less1000(num % 1000) + thousand[k] + " " + ans; 
            }
            k++;
            num /= 1000;
        }
        auto p = ans.find_last_not_of(" ");
        if (p != string::npos) {
            ans = ans.substr(0, p + 1);
        }
        return ans;
    }
    string less1000(int num) {
        if (!num) {
            return "";
        } else if (num < 20) {
            return less20[num] + " ";
        } else if (num < 100) {
            return tens[num / 10] + " " + less1000(num % 10);
        } else {
            return less20[num / 100] + " Hundred " + less1000(num % 100);
        }
    }
    vector<string> less20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousand{"", "Thousand", "Million", "Billion"};
};
