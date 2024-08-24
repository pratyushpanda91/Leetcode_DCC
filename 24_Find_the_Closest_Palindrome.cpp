class Solution {
public:
    string nearestPalindromic(string n) {
        string n1 = small(n);
        string n2 = big(n);
        if(abs(toint(n1) - toint(n)) <= abs(toint(n2) - toint(n))) {
            return n1;
        } else {
            return n2;
        }
    }
    
    bool isp(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }
    
    long long toint(string& s) {
        long long n = 0;
        for(int i = 0; i < s.size(); i++) {
            n = n * 10 + (s[i] - '0');
        }
        return n;
    }
        
    string small(string& s) {
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            //the first place that is smaller
            string prefix(s.size(), '.');
            for(int j = 0; j < i; j++) prefix[j] = s[j];
            for(int d = s[i] - 1; d >= (i == 0 ? '1' : '0'); d--) {
                string news = prefix;
                news[i] = (char)(d);
                for(int j = i + 1; j < s.size(); j++) {
                    if(news[j] == '.') {
                        if(news[n - j - 1] == '.') {
                            news[j] = news[n - j - 1] = '9';
                        } else {
                            news[j] = news[n - j - 1];
                        }
                    }
                }
                if(isp(news)) {
                    return news;
                }
            }
        }
        if(s.size() == 1) return "0";
        else return string(s.size() - 1, '9');
    }
    
    string big(string& s) {
        int n = s.size();
        for(int i = n - 1; i >= 0; i--) {
            //the first place that is bigger
            string prefix(s.size(), '.');
            for(int j = 0; j < i; j++) prefix[j] = s[j];
            for(int d = s[i] + 1; d <= '9'; d++) {
                string news = prefix;
                news[i] = (char)(d);
                for(int j = i + 1; j < s.size(); j++) {
                    if(news[j] == '.') {
                        if(news[n - j - 1] == '.') {
                            news[j] = news[n - j - 1] = '9';
                        } else {
                            news[j] = news[n - j - 1];
                        }
                    }
                }
                if(isp(news)) {
                    return news;
                }
            }
        }
        string ans(s.size() + 1, '0');
        ans[0] = ans[ans.size() - 1] = '1';
        return ans;
    }
};
