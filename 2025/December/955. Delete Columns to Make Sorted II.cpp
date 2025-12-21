class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        vector<bool> sorted(strs.size() - 1, false);

        for(int i=0;i<strs[0].size();i++){
            bool check=true;
            
            for(int j=0;j<strs.size()-1;j++){
                if(!sorted[j] && strs[j][i]>strs[j+1][i]){
                    check=false;
                    break;
                }
            }

            if(check==false){
                count++;
                continue;
            } 
            
            for(int j=0;j<strs.size()-1;j++){
                if(!sorted[j] && strs[j][i]<strs[j+1][i]){
                    sorted[j]=true;
                }
            }
        }
        return count;
    }
};
