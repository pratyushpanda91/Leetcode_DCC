class Solution {
  public:
    int missingNumber(int n, vector<int>& arr) {
     return ((n * (n+1)) / 2) - accumulate(arr.begin(), arr.end(), 0);
}
};
