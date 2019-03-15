// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution 
{
public:
  string change(string s) 
  {
    string result = "!";
    for (int i = 0; i < s.length(); i++) 
    {
      result += "#";
      result += s[i];
    }
    result += "#?";
    return result;
  }
  string longestPalindrome(string s)
  {
    if (0 == s.length())
    {
      return "";
    }
    string new_s = this->change(s);
    int size = new_s.length();
    int* prad = new int[size];
    int right_end{}, pos{};//记录匹配到的回文字符串达到的最右边，和该字符串的中心位置
    for (int i = 1; i < size - 1; i++) 
    {
      if (right_end > i)
      {
        prad[i] = min(right_end - i, prad[2 * pos - i]);
      }
      else
      {
        prad[i] = 0;
      }
      while (new_s[i - prad[i] - 1] == new_s[i + prad[i] + 1])
      {
        prad[i]++;
      }
      if (i + prad[i] > right_end) 
      {
        right_end = i + prad[i];
        pos = i;
      }
    }
    int maxLen{}, start_pos{};
    for (int i = 1; i < size - 1; i++)
    {
      if (maxLen < prad[i])
      {
        maxLen = prad[i];
        start_pos = (i - maxLen - 1) / 2;
      }
    }
    delete[]prad;
    return s.substr(start_pos, maxLen);
  }
};
