class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
        for(char ch:s){
            freq[ch]++;
        }
        int maxOdd = INT_MIN, minEven=INT_MAX;
        for(auto &entry : freq){
            if(entry.second % 2 == 1){
                maxOdd=max(maxOdd,entry.second);
                
            }else{
                minEven = min(minEven,entry.second);
            }
        }
        return maxOdd-minEven;
        
    }
};
