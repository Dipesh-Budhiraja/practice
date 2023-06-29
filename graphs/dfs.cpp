#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

void prepareAdjList(vector<vector<int>> &edges, unordered_map<int, set<int>> &adj) {
    for (auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void dfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, 
vector<int> &componentnodes, int node) {
    componentnodes.push_back(node);
    visited[node] = true;
    // cout << "visited node: " << node << endl;

    for (int i: adj[node]) {
        if(!visited[i]) {
            dfs(adj, visited, componentnodes, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, set<int> > adj;
    prepareAdjList(edges, adj);
    unordered_map<int, bool> visited;

    vector<vector<int>> ans;
    int noOfComponents = 0;
    // visit all components of the graph
    for (int i = 0; i < V; i++) {
        vector<int> componentnodes;
        if (!visited[i]) {
            noOfComponents++;
            dfs(adj, visited, componentnodes, i);
            ans.push_back(componentnodes);
        }
    }

    return ans;
}