#include <map>
#include <set>
#include <vector>
using namespace std;

class TaskManager {
public:
    map<int, pair<int, int>> mp;
    set<pair<int, int>> st;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto it : tasks) {
            st.insert({it[2], it[1]});
            mp[it[1]] = {it[0], it[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        pair<int, int> p = mp[taskId];
        st.erase({p.second, taskId});
        st.insert({newPriority, taskId});
        mp[taskId] = {p.first, newPriority};
    }
    
    void rmv(int taskId) {
        pair<int, int> p = mp[taskId];
        st.erase({p.second, taskId});
        mp.erase(taskId);
    }
    
    int execTop() {
        if (mp.empty()) return -1;
        auto it = st.end();
        it--;
        pair<int, int> p = *it;
        int ans = mp[p.second].first;
        mp.erase(p.second);
        st.erase(it);
        return ans;
    }
};
