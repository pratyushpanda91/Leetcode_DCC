class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        const int n=nums.size();
        const auto [Dmin, Dmax]=minmax(start, (n-1)-start);
        int d=0;
        for(; d<=Dmin; d++){
            const int x=nums[start-d], y=nums[start+d];
            if (x==target || y==target) return d;
        }
        int sgn=(start==Dmin)?1:-1;
        for(d=Dmin+1; d<=Dmax; d++){
            const int x=nums[start+sgn*d];
            if (x==target) return d;
        }
        return -1;// never reach
    }
};
