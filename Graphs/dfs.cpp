#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void addEdge(int u, int v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void dfs(int node)
{
	visited[node] = true;
	cout << node << " ";
	for(int i: graph[node])
		if(!visited[i])
			dfs(i);
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int node, edge;
		cin >> node >> edge;
		graph.assign(node, vector<int>());
		visited.assign(node, false);
		for(int i = 0; i < edge; i++)
		{
			int u, v;
			cin >> u >> v;
			addEdge(u, v);
		}
		dfs(2); //The example I was verifying my code against, required me to set the source as node number 2.
	}
	return 0;
}