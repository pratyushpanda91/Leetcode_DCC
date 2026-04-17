constexpr int MM=1e6+1;
int pos[MM]={[0 ... MM-1]=-1};
class Solution {
public:
    static vector<int> solveQueries(vector<int>& nums, vector<int>& queries) 
    {
        const int n=nums.size(), n2=n*2;
        int left[n], right[n];
        int xMax=0;
        for(int i=0; i<n2; i++){
            const int x=nums[i%n];
            xMax=max(x, xMax);
            if (i>=n) left[i-n]=pos[x];
            pos[x]=i-n;
        }
        memset(pos, -1, (xMax+1)*sizeof(int)); 
        for(int i=n2-1; i>=0; i--){
            const int x=nums[i%n];
            if(i<n) right[i]=pos[x];
            pos[x]=i;
        }
        for(int& q: queries){
            int x=q;
            q=(x-left[x]==n)?-1:min(x-left[x], right[x]-x);
        }
      
        memset(pos, -1, (xMax+1)*sizeof(int)); 
        return queries;
    }
};
