class Solution {
public:
    vector<int> dijkstra(int n, int start, vector<vector<pair<int, int>>>& graph) {
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > distances[node]) continue;

            for (auto& [neighbor, weight] : graph[node]) {
                int newDist = dist + weight;
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
        return distances;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }

        int minReachable = n, city = -1;

        for (int i = 0; i < n; ++i) {
            vector<int> distances = dijkstra(n, i, graph);
            int reachableCount = 0;
            for (int dist : distances) {
                if (dist <= distanceThreshold) {
                    ++reachableCount;
                }
            }
            if (reachableCount <= minReachable) {
                minReachable = reachableCount;
                city = i;
            }
        }

        return city;
    }
};