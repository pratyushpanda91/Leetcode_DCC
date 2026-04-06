#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2")

static const int _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

long long ht[65536]; 
const long long EMPTY = -1e15;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    
        for(int i = 0; i < 65536; ++i) ht[i] = EMPTY;

        for (const auto& obs : obstacles) {
            long long key = ((long long)obs[0] << 32) | (obs[1] & 0xFFFFFFFFLL);
            int h = (unsigned int)(key ^ (key >> 32)) & 65535; 
            while (ht[h] != EMPTY) h = (h + 1) & 65535;
            ht[h] = key;
        }

        int x = 0, y = 0, dir = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd < 0) {
               
                if (cmd == -1) dir = (dir + 1) & 3;
                else dir = (dir + 3) & 3;
            } else {
              
                int dx = (dir == 1) ? 1 : (dir == 3 ? -1 : 0);
                int dy = (dir == 0) ? 1 : (dir == 2 ? -1 : 0);
                
                while (cmd--) {
                    int nx = x + dx;
                    int ny = y + dy;
                    long long key = ((long long)nx << 32) | (ny & 0xFFFFFFFFLL);
                  
                    int h = (unsigned int)(key ^ (key >> 32)) & 65535;
                    bool hit = false;
                    while (ht[h] != EMPTY) {
                        if (ht[h] == key) { hit = true; break; }
                        h = (h + 1) & 65535;
                    }
                    
                    if (hit) break;
                    x = nx; y = ny;
                }
                int cur = x * x + y * y;
                if (cur > maxDistSq) maxDistSq = cur;
            }
        }
        return maxDistSq;
    }
};