class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int n=nums.size();
        if (nums[0]==nums[1]) return nums[0];
        if (nums[2]==nums[0] | nums[2]==nums[1]) return nums[2];
        int candidate, score=0;
        for(int i=3; i<n; i++){
            const int x=nums[i];
            if (score==0) candidate=x;
            score+=2*(x==candidate)-1;
            if (score>=2) return x;
        }
        return candidate;
    }
};
