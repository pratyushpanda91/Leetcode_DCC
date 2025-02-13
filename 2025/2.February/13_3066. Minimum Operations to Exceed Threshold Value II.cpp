#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        priority_queue<ll,vector<ll>,greater<>>pq;
        for(auto i:nums)
            pq.push(i);

        while(pq.size()>1&&pq.top()<k){
            ll tp1=pq.top();pq.pop();
            ll tp2=pq.top();pq.pop();

            if(tp1>tp2)swap(tp1,tp2);

            pq.push(tp1*2+tp2);

            ans++;
        }

        return ans;
    }
};
