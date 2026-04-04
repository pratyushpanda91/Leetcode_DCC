#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <string>

static const int speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    std::string decodeCiphertext(std::string& encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        const int L = encodedText.length();
        if (L == 0) return "";
        
        const int C = L / rows;
        const char* s = encodedText.data();
        
       
        std::string res(C, ' '); 
       
        std::string out;
        out.reserve(C); 

        for (int j = 0; j < C; ++j) {
            for (int r = 0; r < rows; ++r) {
                int c = j + r;
                if (c >= C) break;
                out += s[r * C + c];
            }
        }

        size_t last = out.find_last_not_of(' ');
        if (last == std::string::npos) return "";
        out.erase(last + 1);

        return out;
    }
};#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <string>

static const int speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    std::string decodeCiphertext(std::string& encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        const int L = encodedText.length();
        if (L == 0) return "";
        
        const int C = L / rows;
        const char* s = encodedText.data();
        
       
        std::string res(C, ' '); 
       
        std::string out;
        out.reserve(C); 

        for (int j = 0; j < C; ++j) {
            for (int r = 0; r < rows; ++r) {
                int c = j + r;
                if (c >= C) break;
                out += s[r * C + c];
            }
        }

        size_t last = out.find_last_not_of(' ');
        if (last == std::string::npos) return "";
        out.erase(last + 1);

        return out;
    }
};
