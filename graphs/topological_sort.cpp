#include "header.h"

void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = 1;

    for (auto neighbour: adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    unordered_map<int, list<int>> adj;
    for (auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<bool> visited(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}