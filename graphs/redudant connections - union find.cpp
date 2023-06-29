#include "header.h"

class Solution {
public:
    int find(int n, vector<int> &parent) {
        int p = parent[n];

        while(p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    bool union_fn(int n1, int n2, vector<int> &parent, vector<int> &rank) {
        int p1 = find(n1, parent);
        int p2 = find(n2, parent);
        cout << "n1: " << n1 << " n2: " << n2 << endl;
        cout << "p1: " << p1 << " p2: " << p2 << endl;
         
        if (p1 == p2) {
            return false;
        }

        // join the nodes
        if (rank[p1] >= rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent;
        vector<int> rank;
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }

        for (auto edge: edges) {
            if (!union_fn(edge[0], edge[1], parent, rank)) {
                return edge;
            }
        }
        return vector<int>();
    }
};