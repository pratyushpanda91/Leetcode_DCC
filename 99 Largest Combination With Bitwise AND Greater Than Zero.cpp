class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        const int BitMax = 24;
        int maxSet = 1;
        int mask = 1;
        
        for (int shift = 0; shift < BitMax; shift++) {
            int count = 0;
            for (int num : candidates) {
                if (num & mask) {
                    count++;
                }
            }
            maxSet = max(maxSet, count);
            mask <<= 1;
        }
        return maxSet;
    }
};
