class Solution {
public:
    int minimizeXor(unsigned num1, unsigned num2) {
        int B=popcount(num2);
        bitset<31> y=num1, x=0;
        for (int b=30; B>=1 && b>=0; b--){
            if (y[b]){
                x[b]=1;
                y[b]=0;
                B--;
            }
        }
        for (int b=0; B>=1 && b<31; b++){
            if (x[b]==0){
                x[b]=1;
                B--;
            }
        }
        return x.to_ulong();
    }
};
