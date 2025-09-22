class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
       unordered_map<int, int> freqMp;
        int maxFreq = 0;
        for (int num : nums) {
            freqMp[num]++;
            maxFreq = std::max(maxFreq, freqMp[num]);
        }

        int maxFreqEleCnt = 0;
        for (auto entry : freqMp) {
            int currEleFreq = entry.second;
            if (currEleFreq == maxFreq) {
                maxFreqEleCnt++;
            }
        }
        return maxFreq * maxFreqEleCnt;
    }
};
