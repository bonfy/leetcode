// The API: int read4(char *buf) reads 4 characters at a time from a file.
//
// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
//
// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
//
// Note:
// The read function may be called multiple times.
//
// Example 1: 
//
//
// Given buf = "abc"
// read("abc", 1) // returns "a"
// read("abc", 2); // returns "bc"
// read("abc", 1); // returns ""
//
//
// Example 2: 
//
//
// Given buf = "abc"
// read("abc", 4) // returns "abc"
// read("abc", 1); // returns ""
//
//


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        while (!cache.empty() && n > 0) {
            buf[cnt++] = cache.front();
            cache.pop();
            n--;
        }
        int len = 4;
        while (n > 0 && len == 4) {
            len = read4(buf + cnt);
            for (int i = n; i < len; i++) {
                cache.emplace(buf[cnt + i]);
            }
            cnt += min(n, len);
            n -= len;
        }
        return cnt;
    }
    queue<char> cache;
};
