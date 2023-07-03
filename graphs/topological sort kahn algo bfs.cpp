#include "header.h"


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int, list<int>> adj;
    for (auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
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

    vector<int> ans;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (int neighbour: adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] ==0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}