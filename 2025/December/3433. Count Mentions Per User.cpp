class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        const int n = events.size();
        vector<int> mention(numberOfUsers);
        vector<int> last_offline(numberOfUsers);
        int all_count = 0;
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
    int ta = stoi(a[1]);
    int tb = stoi(b[1]);
    if (ta != tb) return ta < tb;
  
    if (a[0] == b[0]) return false;
    return a[0] == "OFFLINE";
});
        

        for(vector<string>& event:events){
            int curr_time = stoi(event[1]);
            if(event[0][0] == 'M'){
                if(event[2][0] == 'A'){
                    ++all_count;
                } else if (event[2][0] == 'H'){
                    for(int i=0;i<numberOfUsers;++i){
                        if(curr_time >= last_offline[i]){
                            ++mention[i];
                        }
                    }
                } else {
                    int i = 0;
                    string& ids = event[2];
                    const int m = ids.size();
                    while(i<m){
                        int num = 0;
                        i += 2;
                        while(i<m && ids[i]!=' '){
                            num = (ids[i++]-'0') + num*10;
                        }
                        ++mention[num];
                        ++i;
                    }
                }
            } else {
                int id = stoi(event[2]);
                last_offline[id] = curr_time+60;
            }
        }
        


            
        for(int i=0;i<numberOfUsers;++i){
            mention[i] += all_count;
        }
        return mention;
        
    
        
    }
};
