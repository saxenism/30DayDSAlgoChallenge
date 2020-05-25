/*
#Link to Question:
https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/description/

#Question:
Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in the graph. Calculate the total number of connected components in the graph. A connected component is a set of vertices in a graph that are linked to each other by paths.

Input Format:

First line of input line contains two integers n and e. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. 

Output Format:

For each input graph print an integer x denoting total number of connected components.

Constraints:

All the input values are well with in the integer range.
*/
#include <bits/stdc++.h>

#define pb push_back
#define endl "\n"
#define lli long long int
#define i_am_iron_man ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<vector<lli>> graph;
vector<bool> visited;

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void dfs(lli node)
{
	visited[node] = true;
	for(lli i : graph[node])
		if(!visited[i])
			dfs(i);
}

int main()
{
	i_am_iron_man
	lli n, e, connected_comp = 0;
	cin >> n >> e;
	graph.assign(n, vector<lli>());
	visited.assign(n, false);
	while(e--)
	{
		lli u, v;
		cin >> u >> v;
		addEdge(--u, --v);
	}
	for(lli i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			++connected_comp;
			dfs(i);
		}
	}
	cout << connected_comp << endl;
	return 0;
}
