class Solution {
public:
    long long H3(long long n){
        return n<0?0:(n+1)*(n+2)/2;
    }
    long long distributeCandies(int n, int limit) {
        return H3(n)-3LL*H3(n-limit-1)+3LL*H3(n-2*(limit+1))-H3(n-3*(limit+1));
    }
};
