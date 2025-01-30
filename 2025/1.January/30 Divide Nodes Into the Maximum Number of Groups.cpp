class Solution {
public:
    int magnificentSets(int numNodes, vector<vector<int>>& edgesList) {
        vector<vector<int>> adjacencyList(numNodes);
        for (auto& edge : edgesList) {
            int node1 = edge[0] - 1, node2 = edge[1] - 1;
            adjacencyList[node1].push_back(node2);
            adjacencyList[node2].push_back(node1);
        }
        vector<int> nodeDistances(numNodes);
        for (int startNode = 0; startNode < numNodes; ++startNode) {
            queue<int> nodeQueue{{startNode}};
            vector<int> distance(numNodes);
            distance[startNode] = 1;
            int maxDistance = 1;
            int rootNode = startNode;
            while (!nodeQueue.empty()) {
                int currentNode = nodeQueue.front();
                nodeQueue.pop();
                rootNode = min(rootNode, currentNode);
                for (int neighbor : adjacencyList[currentNode]) {
                    if (distance[neighbor] == 0) {
                        distance[neighbor] = distance[currentNode] + 1;
                        maxDistance = max(maxDistance, distance[neighbor]);
                        nodeQueue.push(neighbor);
                    } else if (abs(distance[neighbor] - distance[currentNode]) != 1) {
                        return -1;
                    }
                }
            }
            nodeDistances[rootNode] = max(nodeDistances[rootNode], maxDistance);
        }
        return accumulate(nodeDistances.begin(), nodeDistances.end(), 0);
    }
};
