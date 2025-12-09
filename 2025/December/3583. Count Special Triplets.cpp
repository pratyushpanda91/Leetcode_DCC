class Solution {
  public:
    virtual vector<int> findDuplicates(vector<int>& arr){
      vector<int> ans;
      
      for(int i=0; i<arr.size(); i++){
        int ind = abs(arr[i])-1;
        if(arr[ind] < 0)
          ans.push_back(abs(arr[i]));
        else
          arr[ind]*=(-1);
      }
      
      return ans;
    }
};
