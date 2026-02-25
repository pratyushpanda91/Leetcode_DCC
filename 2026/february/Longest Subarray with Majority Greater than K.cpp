class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int cnt = 0, len = 0;
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]<=k)cnt--;
            else cnt++;
            
            if(cnt>0){
                len = max(len, i+1);
            }
            
            auto it = mp.find(cnt-1);
            if(it != mp.end()){
                len = max(len, i-it->second);
            }
            
            if(mp.find(cnt) == mp.end()){
                mp[cnt] = i;
            }
        }
        
        return len;
    }
};
