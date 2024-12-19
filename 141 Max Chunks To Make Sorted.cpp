#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0; // Number of chunks
        int maxVal = 0; // Tracks the maximum value in the current segment
        
        for (int i = 0; i < arr.size(); i++) {
            maxVal = max(maxVal, arr[i]); // Update the maximum value seen so far
            if (maxVal == i) {
                chunks++; // A new chunk can be formed
            }
        }
        
        return chunks;
    }
};
