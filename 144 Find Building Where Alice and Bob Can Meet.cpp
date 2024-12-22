class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int queryCount = queries.size();
        vector<int> result(queryCount, -1);
        vector<vector<pair<int, int>>> deferredQueries(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int queryIndex = 0; queryIndex < queryCount; ++queryIndex) {
            int aliceStart = queries[queryIndex][0];
            int bobStart = queries[queryIndex][1];
            if (aliceStart == bobStart) {
                result[queryIndex] = aliceStart;
            } else if (aliceStart < bobStart && heights[aliceStart] < heights[bobStart]) {
                result[queryIndex] = bobStart;
            } else if (aliceStart > bobStart && heights[aliceStart] > heights[bobStart]) {
                result[queryIndex] = aliceStart;
            } else {
                int maxHeight = max(heights[aliceStart], heights[bobStart]);
                int maxIndex = max(aliceStart, bobStart);
                deferredQueries[maxIndex].emplace_back(maxHeight, queryIndex);
            }
        }
        for (int currentBuilding = 0; currentBuilding < n; ++currentBuilding) {
            while (!minHeap.empty() && minHeap.top().first < heights[currentBuilding]) {
                int queryIndex = minHeap.top().second;
                minHeap.pop();
                result[queryIndex] = currentBuilding;
            }
            for (auto& query : deferredQueries[currentBuilding]) {
                minHeap.emplace(query.first, query.second);
            }
        }

        return result;
    }
};
