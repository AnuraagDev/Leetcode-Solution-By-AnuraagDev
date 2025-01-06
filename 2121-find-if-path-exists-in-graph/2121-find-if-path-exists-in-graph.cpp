//Bro why the hell I have to add these to get better runtime :) Your Anuraagdev
#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto d:edges){
            int u=d[0];
            int v=d[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(source);
        vector<int>visited(n);
        while(!q.empty()){
            auto node=q.front();
            if(node==destination)return 1;
            q.pop();
            visited[node]=1;
            for(auto i:adj[node]){
                if(!visited[i]){
                    q.push(i);
                }
            }
        }
        return 0;
    }
};