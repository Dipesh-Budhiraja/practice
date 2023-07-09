#include  "header.h"
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int,int>>> adj;

    //making adjajency list
    for(int i = 0 ; i < edges ; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    

    //declaring set and dist datastructure 
    set<pair<int,int>> st;
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty())
    {
       auto top = *(st.begin());
       int nodedist = top.first;
       int node = top.second;
       st.erase(st.begin());
       for(auto it : adj[node])
       {
           int newdist = nodedist + it.second;
           if(newdist < dist[it.first])
           {
               auto record = st.find(make_pair(dist[it.first], it.first));
               if(record != st.end())
               {
                   st.erase(record);
               }
               dist[it.first] = newdist;
               st.insert(make_pair(newdist,it.first));
           }
       }   
    }

    return dist;
}