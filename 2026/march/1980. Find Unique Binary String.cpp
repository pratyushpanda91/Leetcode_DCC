class Solution {

private:

    int to_dec(string& s, int n){
        int num = 0;
        int pow = 1;
        for(int i=n-1;i>=0;--i){
            if(s[i]=='1'){
                num+=pow;
            }
            pow*=2;
        }
        return num;
    }

    string to_bin(int num, int n){
        string s = "";
        while(num){
            if(num&1){
                s+="1";
            }
            else{
                s+="0";
            }
            num/=2;
        }
        int cur_size = s.size();
        for(int i=0;i<n-cur_size;++i){s+="0";}
        reverse(s.begin(),s.end());
        return s;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> seen;
        int n = nums[0].size();  
        for (string& s : nums) {
            seen.insert(to_dec(s, n)); 
        }
        for (int i=0; i<(1<<n); ++i) {
            if (!seen.count(i)) {
                return to_bin(i, n);
            }
        }
        return "";
    }
};
