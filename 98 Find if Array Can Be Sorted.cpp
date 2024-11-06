class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int cnt = -1;
        int prevMax = -1, currMin = 1e9, currMax = -1;
        for(auto it: nums){
            int currBits = __builtin_popcount(it);
            if(cnt == -1 || currBits == cnt){
                cnt = currBits;
                currMin = min(currMin, it);
                currMax = max(currMax, it);
            }
            else{
                if(prevMax > currMin) return false;
                cnt = currBits;
                prevMax = currMax;
                currMin = it;
                currMax = it;
            }
        }
        if(prevMax > currMin) return false;
        return true;
    }
};
