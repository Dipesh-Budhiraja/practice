#include "header.h" 

void prepareAdjList(vector<pair<int, int>> &edges, unordered_map<int, set<int>> &adj) {
    for (auto edge: edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, 
        vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        
        for (auto i: adj[frontnode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> ans;

    // prepare adj list
    prepareAdjList(edges, adj);

    // visit all components of the graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adj, visited, ans, i);
        }
    }

    return ans;

}