class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int n) {
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currentDist, node] = pq.top();
            pq.pop();

            if (currentDist > distance[node]) continue;

            for (auto& [neighbor, weight] : adj[node]) {
                if (currentDist + weight < distance[neighbor]) {
                    distance[neighbor] = currentDist + weight;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        return distance;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back({i + 1, 1});
        }
        vector<int> distance = dijkstra(adj, n);

        vector<int> ans;
        for (auto& query : queries) {
            int from = query[0], to = query[1];
            adj[from].push_back({to, 1});

            if (distance[from] + 1 < distance[to]) {
                distance[to] = distance[from] + 1;

                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
                pq.push({distance[to], to});

                while (!pq.empty()) {
                    auto [currentDist, node] = pq.top();
                    pq.pop();

                    if (currentDist > distance[node]) continue;

                    for (auto& [neighbor, weight] : adj[node]) {
                        if (currentDist + weight < distance[neighbor]) {
                            distance[neighbor] = currentDist + weight;
                            pq.push({distance[neighbor], neighbor});
                        }
                    }
                }
            }
            ans.push_back(distance[n - 1] == INT_MAX ? -1 : distance[n - 1]);
        }

        return ans;
    }
};
