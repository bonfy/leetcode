// Note: This is a companion problem to the System Design problem: Design TinyURL.
//
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
//
// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
//


class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string su = "";
        do {
            gensu(su);
        } while (db.find(su) != db.end());
        db[su] = longUrl;
        return su;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[shortUrl];
    }
    
private:
    unordered_map<string, string> db;
    void gensu(string& su) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> outer(0, 2);
        std::uniform_int_distribution<> rnum(0, 9);
        std::uniform_int_distribution<> rchar(0, 26);
        int r = 0;
        for (int i = 0; i < 6; i++) {
            r = outer(gen);
            if (r == 0) {
                r = rnum(gen);
                su += ('0' + r);
            } else if (r == 1) {
                r = rchar(gen);
                su += ('a' + r);
            } else {
                r = rchar(gen);
                su += ('A' + r);
            }
        }
        return;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
