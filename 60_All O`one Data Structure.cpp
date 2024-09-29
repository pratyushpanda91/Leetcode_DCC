class AllOne {
public:

    unordered_map<string,int> allInOne;
    pair<string,int> maxi = {"",INT_MIN};
    pair<string,int> mini = {"",INT_MAX};

    AllOne(){}       
    
    void inc(string key) {
        allInOne[key]++;
        if(maxi.second <= allInOne[key]){
            maxi = {key,allInOne[key]};
        }
        if(mini.second >= allInOne[key]){
            mini = {key,allInOne[key]};
        }
        else if(mini.first == key){
            int mi = INT_MAX;
            for(auto it: allInOne){
                if(it.second < mi){
                    mini = {it.first,it.second};
                    mi = it.second;
                }
            }
        }
    }
    
    void dec(string key) {
        allInOne[key]--;
        if(allInOne[key] == 0){
            allInOne.erase(key);
        }
        if(allInOne.empty()){
            maxi = {"",INT_MIN};
            mini = {"",INT_MAX};
        }
        else{
            if(maxi.first == key){
                int mx = INT_MIN;
                for(auto it: allInOne){
                    if(it.second > mx){
                        maxi = {it.first,it.second};
                        mx = it.second;
                    }
                }
            }
            if(mini.first == key){
                int mi = INT_MAX;
                for(auto it: allInOne){
                    if(it.second < mi){
                        mini = {it.first,it.second};
                        mi = it.second;
                    }
                }
            }
        }
    }
    
    string getMaxKey() {
        return maxi.first;
    }
    
    string getMinKey() {
        return mini.first;
    }
};
