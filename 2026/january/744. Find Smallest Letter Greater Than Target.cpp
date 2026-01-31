class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int n=letters.size();
        int l=0, r=n-1, ans=n;
        while(l<=r){
            int m=(r+l)/2;
            if (target<letters[m]){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return letters[ans%n];
    }
};
