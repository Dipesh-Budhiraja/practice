#include "header.h"
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;
    
    void addEdge(int u,int v, int weight) {
        pair<int, int> p = {v, weight};
        adj[u].push_back(p);
    }

    void printAdjList() {
        for(auto i: adj) {
            cout << i.first << " -> ";
            for(auto j: i.second) {
                cout << "(" << j.first << "," << j.second << ")";
            }
            cout << endl; 
        }
    }

    void dfs(int node, vector<bool> &visited, stack<int> &s) {
        visited[node] = true;

        for (auto neighbour: adj[node]) {
            if (!visited[neighbour.first]) {
                dfs(neighbour.first, visited, s);
            }
        }
        s.push(node);
    }

    void findShortestDist(int src, vector<int> &dist, stack<int> &s) {
        dist[src] = 0;

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (dist[top] != INT_MAX) {
                for (auto neighbour: adj[top]) {
                    if (dist[top] + neighbour.second < dist[neighbour.first]) {
                        dist[neighbour.first] = dist[top] + neighbour.second;
                    }
                }
            }
        }
    }

};

int main() {
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.printAdjList();

    int n = 6; // 0 -> 5
    vector<bool> visited(n, false);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.dfs(i, visited, s);
        }
    }

    vector<int> dist(n, INT_MAX);
    g.findShortestDist(1, dist, s);
    for (auto i: dist) {
        cout << i << " ";
    }
    
    return 0;
}
