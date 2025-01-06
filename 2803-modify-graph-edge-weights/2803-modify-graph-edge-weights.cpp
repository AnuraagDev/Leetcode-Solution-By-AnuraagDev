class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            graph[u].emplace_back(v, i);
            graph[v].emplace_back(u, i);
        }

        vector<vector<int>> distance(n, vector<int>(2, INT_MAX));
        distance[src][0] = distance[src][1] = 0;

        dijkstra(graph, edges, distance, src, 0, 0);
        int remaining = target - distance[dest][0];
        if (remaining < 0) return {};

        dijkstra(graph, edges, distance, src, remaining, 1);
        if (distance[dest][1] < target) return {};

        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 1;
        }
        return edges;
    }

private:
    void dijkstra(const vector<vector<pair<int, int>>>& graph, vector<vector<int>>& edges, vector<vector<int>>& distance, int src, int adjust, int run) {
        int n = graph.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        distance[src][run] = 0;

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();
            if (currDist > distance[node][run]) continue;

            for (auto& [neighbor, idx] : graph[node]) {
                int weight = edges[idx][2];
                if (weight == -1) weight = 1;

                if (run == 1 && edges[idx][2] == -1) {
                    int newWeight = adjust + distance[neighbor][0] - distance[node][1];
                    if (newWeight > weight) edges[idx][2] = weight = newWeight;
                }

                if (distance[neighbor][run] > distance[node][run] + weight) {
                    distance[neighbor][run] = distance[node][run] + weight;
                    pq.push({distance[neighbor][run], neighbor});
                }
            }
        }
    }
};
