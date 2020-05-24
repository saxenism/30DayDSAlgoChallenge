#include <bits/stdc++.h>

#define pb push_back
#define endl "\n"

using namespace std;

vector<vector<int>> graph;
vector <bool> visited;
vector <int> dist;
vector <int> parent;

void addEdge(int u, int v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void bfs(int source)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;
	dist[source] = 0;
	parent[source] = -1;
	while(!q.empty())
	{
		int f = q.front();
		cout << f << " "; //Or whatever the operation being required here.
		q.pop();
		for(int i: graph[f])
		{
			if(!visited[i])
			{
			    visited[i] = true;
				q.push(i);
				dist[i] = dist[f] + 1;
				parent[i] = f;
			}
		}
	}
	cout << endl;
}

void findPath(int node)
{
	if(!visited[node])
		cout << "-1" << endl;
	else
	{
		vector <int> path;
		for(int i = node; i != -1; i = parent[node])
			path.pb(i);
		reverse(path.begin(), path.end());
		cout << "Path: ";
		for(auto i: path)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int node, edge;
		cin >> node >> edge;
		visited.assign(node, false);
		parent.assign(node, -1);
		dist.assign(node, 0);
		graph.assign(node, vector<int>());
		int u, v;
		for(int i = 0; i < edge; i++)
		{
			cin >> u >> v;
			addEdge(u, v);
		}
		//for(int i = 0; i < node; i++)
		//	if(!visited[i])
		//		bfs(i);
		//for(int i = 0; i < node; i++)
			//findPath(i);
		bfs(0);
	}
	return 0;
}