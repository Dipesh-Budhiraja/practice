#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <list>
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



// BFS - kahn algo modifification 

int detectCycleInDirectedGraph(int v, vector < pair < int, int>> & edges) {
    // create adj list
    unordered_map<int, list<int>> adj;
    for (auto edge: edges) {
        int u = edge.first - 1; // adjusting nodes from 1->n to 0 -> n-1
        int v = edge.second - 1;
        adj[u].push_back(v);
    }
    //find indegree of all nodes
    vector<int> indegree(v);
    for (auto i: adj) {
        // key(i): [j1, j2, j3]
        for (auto j: i.second) {
            indegree[j]++;
        }
    }
    // push nodes of 0 indegree in queue
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        cnt++;
        for (int neighbour: adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] ==0) {
                q.push(neighbour);
            }
        }
    }
    if (cnt == v) {
        return false; // no cycle present
    }
    return true; // cycle is present
}