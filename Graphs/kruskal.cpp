#include <bits/stdc++.h>

using namespace std;

struct edge{
	int from;
	int to;
	int wt;
};

int parent[100005], R[100005], sum = 0;
edge graph[100005];

int find(int a)
{
	if(parent[a] < 0)
		return a;
	else
		return (parent[a] = find(parent[a]));
}

void union_fun(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if(R[x] > R[y])
	{
		R[x] += R[y];
		parent[y] = x;
	}
	else
	{
		R[y] += R[x];
		parent[x] = y;
	}
}

bool comparator(edge a, edge b)
{
	if(a.wt < b.wt)
		return true;
	return false;
}

int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		parent[i] = -1;
		R[i] = 1;
	}
	for(int i = 1; i <= m; i++)
		cin >> graph[i].from >> graph[i].to >> graph[i].wt;
	sort(graph+1, graph+m+1, comparator);
	for(int i = 1; i <= m; i++)
	{
		if(find(graph[i].from) != find(graph[i].to))
		{
			union_fun(graph[i].from, graph[i].to);
			sum += graph[i].wt;
		}
	}
	cout << sum << endl;
	return 0;
}
