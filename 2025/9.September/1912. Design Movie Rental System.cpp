class MovieRentingSystem {
private:
    set<pair<int, pair<int, int>>> s; 
    unordered_map<long long, int> mp; 
    set<pair<int, pair<int, int>>> rented; 
    unordered_map<int, set<pair<int, int>>> movieToPS; 

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto it : entries) {
            s.insert({it[2], {it[0], it[1]}});
            long long key = 1LL * it[0] * 1000000 + it[1];
            mp[key] = it[2];
            movieToPS[it[1]].insert({it[2], it[0]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int cnt = 0;
        for (auto it : movieToPS[movie]) {
            if (cnt == 5) break;
            ans.push_back(it.second);
            cnt++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        long long key = 1LL * shop * 1000000 + movie;
        int price = mp[key];
        s.erase({price, {shop, movie}});
        rented.insert({price, {shop, movie}});
        movieToPS[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        long long key = 1LL * shop * 1000000 + movie;
        int price = mp[key];
        s.insert({price, {shop, movie}});
        rented.erase({price, {shop, movie}});
        movieToPS[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end(); it++) {
            if (cnt == 5) break;
            ans.push_back({it->second.first, it->second.second});
            cnt++;
        }
        return ans;
    }
};
