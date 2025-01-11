#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        // Step 1: Count character frequencies
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Count odd frequencies
        int oddCount = 0;
        for (auto& [ch, count] : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        // Step 3: Check feasibility
        if (k < oddCount || k > s.size()) {
            return false;
        }
        return true;
    }
};
