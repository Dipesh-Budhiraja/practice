#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;



void prepareAdjList(vector<vector<int>> &edges, unordered_map<int, set<int>> &adj) {
    for (auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

bool isBFSCyclic(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, int node) {
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = true;
    while(!q.empty()) {
        int frontnode = q.front();
        q.pop();
        
        for (auto neighbour: adj[frontnode]) {
            if (visited[neighbour] && neighbour != parent[frontnode]) {
                return true; //cycle
            } else if (!visited[neighbour]) {
                q.push(neighbour);
                parent[neighbour] = frontnode;
                visited[neighbour] = true;
            }
        }
    }
    return false; // no cycle
}

bool isDFSCyclic(unordered_map<int, set<int>> &adj,
                 unordered_map<int, bool> &visited, int node, int parent) {
    visited[node] = true;

    for (int neighbour: adj[node]) {
        if (!visited[neighbour]) {
            bool isCycle = isDFSCyclic(adj, visited, neighbour, node);
            if (isCycle) {
                return true;
            }
        } else if (neighbour != parent) {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;

    prepareAdjList(edges, adj);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool isCyclic = isDFSCyclic(adj, visited, i, -1);
            if (isCyclic) {
                return "Yes";
            }
        }
    }
    return "No";

}
