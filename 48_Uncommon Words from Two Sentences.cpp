class Solution {
public:
    inline static vector<string> toStringVec(string& s){
        stringstream ss(s);
        vector<string> ans;
        while (!ss.eof()){
            string tmp;
            ss>>tmp;
            ans.push_back(tmp);
        }
        ss.clear();
        return ans;
    }
    static vector<string> uncommonFromSentences(string& s1, string& s2) {
        auto ss1=toStringVec(s1);
        auto ss2=toStringVec(s2);
        unordered_map<string, int> freq;
        freq.reserve(ss1.size()+ss2.size());
        for(auto& s: ss1) freq[s]++;
        for(auto& s: ss2) freq[s]++;
        vector<string> ans;
        for(auto& [s,f]: freq){
            if(f==1) ans.push_back(s);
        }
        return ans;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
