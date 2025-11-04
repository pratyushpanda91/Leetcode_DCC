class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> answer;
        for(int i=0;i<=n-k;i++){
            unordered_map<int,int> freqMap;
            for(int j=i;j<i+k;j++){
                freqMap[nums[j]]++;
            }
            vector<pair<int,int>> freqVec;
            for(auto&p : freqMap){
                freqVec.push_back({p.second,p.first});
            }
            sort(freqVec.begin(),freqVec.end(),[](pair<int,int> &a,pair<int,int> &b){
                if(a.first == b.first)
                    return a.second>b.second;
                return a.first > b.first;
            });
            int sum=0;
            int taken=0;
            for(auto&p : freqVec){
                if(taken >= x) break;
                sum+=p.first*p.second;
                taken++;
            }
            answer.push_back(sum);
        }
        return answer;
    }
};
