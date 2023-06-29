#include <vector>
#include <unordered_map> 
#include <list>
using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create adjacency list 
	unordered_map<int, list<int> > adj;
	for (auto edge: edges) {
		int u = edge.first;
		int v = edge.second;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	// bfs
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty()) {
		int front = q.front();
		q.pop();

		for (auto neighbour: adj[front]) {
			if (!visited[neighbour]) {
				visited[neighbour] = true;
				parent[neighbour] = front;
				q.push(neighbour);
			}
		}
	}

	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s) {
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
