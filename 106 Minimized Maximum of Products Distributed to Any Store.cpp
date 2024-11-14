class Solution {
public:
    bool isPossible(int target, int n, vector<int> &q){
        int sz = q.size();
        int cnt = 0;
        for(int i=0;i<sz;i++){
            int div = q[i]/target;
            int rem = q[i] % target;
            cnt += div;
            if(rem > 0) cnt ++;
        }
        return cnt <= n;

    }
    int minimizedMaximum(int n, vector<int>& q) {
        int sz = q.size();
        int mx = 0;
        for(int i=0;i<sz;i++) {
            mx = max(mx, q[i]);
        }
        int lo = 1, hi = mx;
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(mid,n,q)) {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};
