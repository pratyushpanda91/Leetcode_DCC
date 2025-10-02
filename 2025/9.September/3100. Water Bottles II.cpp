class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
       int cnt=numBottles;
        int ans=numBottles;
        while(ans>=numExchange){
            ans-=numExchange;
            ans++;
            cnt++;
            numExchange++;
            
        }
        return cnt;
    }
};
