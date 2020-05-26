/*

Input:
6 5
1 2
2 3
2 4
4 5
4 6

Expected Output:
[1, 0, 1, 1, 2, 2]

*/


#include <bits/stdc++.h>

#define lli long long int
#define endl "\n"
#define pb push_back

using namespace std;

vector <vector<lli>> graph;
vector <bool> visited;
vector <lli> dist;

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void dfs(lli node)
{
	visited[node] = true;
	for(lli i: graph[node]){
		if(!visited[i]){
			dist[i] = dist[node] + 1;
			dfs(i);
		}
	}
}

int main()
{
	lli n, e;
	cin >> n >> e;
	graph.assign(n, vector<lli>());
	visited.assign(n, false);
	dist.assign(n, 0);
	while(e--)
	{
		lli u, v;
		cin >> u >> v;
		addEdge(--u, --v);
	}
	lli source = 2;
	--source;
	dfs(source);
	for(lli i: dist)
		cout << i << " ";
	cout << endl;
	return 0;
}