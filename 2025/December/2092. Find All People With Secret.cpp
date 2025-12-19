class Solution {
    int find(vector<int>& sets, int v) {
        return sets[v] < 0 ? v : sets[v] = find(sets, sets[v]);
    }

    void unite(vector<int>& sets, int u, int v) {
        u = find(sets, u);
        v = find(sets, v);

        if (u == v) return;

        if (sets[u] > sets[v]) swap(u, v);

        sets[u] += sets[v];
        sets[v] = u;
    }

public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });

        vector<int> sets(n, -1);
        unite(sets, 0, firstPerson);

        for (int l = 0, r = 0; l < meetings.size();) {
            for (; r < meetings.size() && meetings[l][2] == meetings[r][2]; ++r) {
                unite(sets, meetings[r][0], meetings[r][1]);
            }

            for (int s = find(sets, 0); l < r; ++l) {
                if (find(sets, meetings[l][0]) != s) sets[meetings[l][0]] = -1;
                if (find(sets, meetings[l][1]) != s) sets[meetings[l][1]] = -1;
            }
        }

        vector<int> res;
        for (int i = 0, s = find(sets, 0); i < n; ++i) {
            if (find(sets, i) == s) res.push_back(i);
        }

        return res;
    }
};
