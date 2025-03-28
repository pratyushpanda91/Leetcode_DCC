class Solution {
  public:
    
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<vector<int>>vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({finish[i], start[i]});
        }
        sort(vec.begin(), vec.end());
        
        //int ans=1;
        int end=vec[0][0];
        int maxi=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i][1]>end){
                maxi++;
                end=vec[i][0];
            }
            

        }
        return maxi;
        
    }
};
