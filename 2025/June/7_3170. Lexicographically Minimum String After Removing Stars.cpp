class Solution {
public:
    string clearStars(string s) {
    priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> minh;
    unordered_map<int,bool> mpp;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                mpp[-minh.top().second] = true;
                minh.pop();
            } else {
                minh.push({s[i], -i});
            }
        }
        string res;
        for(int i = 0; i < s.size(); i++) {
            if(mpp.count(i) || s[i] == '*') continue;
            res += s[i];
        }
        return res;
    }
};
