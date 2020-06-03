#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent, in, low;
vector<pair<int, int>> 

int timer;
bool hasBridge;

void addEdge(int a, int b)
{
	graph[a].push_back(b);
	graph[b].push_back(a);
}

void solve(int node)
{
	visited[node] = true;
	in[node] = low[node] = timer++;
	for(int i: graph[node])
	{
		parent[i] = node;
		if(visited[i]){
			if(i = parent[node])
				continue;
			else{
				low[node] = min(low[node], in[i]);
			}
		}
	}
}

int main()
{
	int n, e;
	cin >> n >> e;
	while(e--)
	{
		int a, b;
		cin >> a >>b;
		addEdge(a, b);
	}
	return 0;
}