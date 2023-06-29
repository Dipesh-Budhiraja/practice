#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void prepareAdjList(vector<pair<int, int>> &edges, unordered_map<int, set<int>> &adj) {
    for (auto edge: edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].insert(v);
    }
}

bool isDFSCyclic(unordered_map<int, set<int>> &adj,
                 unordered_map<int, bool> &visited, 
                 unordered_map<int, bool> &dfs_visited, 
                 int node) {
    visited[node] = true;
    dfs_visited[node] = true;
    for (int neighbour: adj[node]) {
        if (!visited[neighbour]) {
            bool isCycle = isDFSCyclic(adj, visited, dfs_visited, neighbour);
            if (isCycle) {
                return true;
            }
        } else if (visited[neighbour] == true && dfs_visited[neighbour] == true) {// visited == true && dfs_visited == true
            return true;
        }
    }
    dfs_visited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int>> & edges) {
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfs_visited;
    prepareAdjList(edges, adj);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool isCyclic = isDFSCyclic(adj, visited, dfs_visited, i);
            if (isCyclic) {
                return 1;
            }
        }
    }
    return 0;
}