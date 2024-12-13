class Solution {
public:
    using int2=pair<int, int>;
    static long long findScore(vector<int>& nums) {
        const int N=100000, n=nums.size();
        bitset<N> mark=0;
        vector<long long> nIdx(n);
        for(int i=0; i<n; i++)
            nIdx[i]=((long long)nums[i]<<20)+i;
        sort(nIdx.begin(), nIdx.end());
        long long sum=0;
        for(auto info: nIdx){
            int x=info>>20, i=info &((1<<20)-1);
            if (mark[i]) continue;
            sum+=x;
            mark[i]=1;
            if (i>0) mark[i-1]=1;
            if (i<n-1) mark[i+1]=1;
        }
        return sum;
    }
};
