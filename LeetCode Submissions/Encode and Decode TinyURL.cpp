class Solution {
public:
    string base="http://tinyurl.com/";
    int count=0;
    unordered_map<string, string> um;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code=base+to_string(count);
        count++;

        um[code]=longUrl;

        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string c;
        int slashCount=0, i=0;
        for(; i<shortUrl.size(); i++)
        {
            if(shortUrl.at(i)=='/')
                slashCount++;

            if(slashCount==3)
                break;
        }

        c=shortUrl.at(i+1);

        return um.at(base+c);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
