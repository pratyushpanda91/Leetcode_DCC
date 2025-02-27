class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> stt(arr.begin(),arr.end());
        int maxi=2;
        for (int i=0;i<arr.size();i++) {
            for (int j=i+1;j<arr.size();j++) {
                int count=2,num_1=arr[i],num_2=arr[j];
                while (stt.count(num_1+num_2)) {
                    int sum=num_1+num_2;
                    num_1=num_2;
                    num_2=sum;
                    count++;
                }
                maxi=max(maxi,count);
            }
        }
        return(maxi>2)?maxi:0;
    }
};
