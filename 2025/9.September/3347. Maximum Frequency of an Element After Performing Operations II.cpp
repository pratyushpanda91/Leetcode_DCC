class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations)    
    {
        const int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int ans=0, cnt=0;
        int l=0, r=0;

        for (int i=0; i<n; i++) {
            const int x=nums[i], L=max(1,x-k), R=min(nums.back(), x+k);

            int f=1;
            int j=i+1;
            for (;j<n && nums[j]==x; j++) f++;
            i=j-1; 

            while (l<n && nums[l]<L) l++;

            r=(r>i)?r:i;
            while (r+1<n && nums[r+1]<=R) r++;

            cnt=r-l+1;
            ans=max(ans, f+min(cnt-f, numOperations));
        }

        for (l=0, r=0; r<n; r++) {
            int x=nums[r], L=max(1, x-2*k);
            while (l<r && nums[l]<L) l++;
            ans=max(ans, min(r-l+1, numOperations));
        }
        return ans;
    }
};
