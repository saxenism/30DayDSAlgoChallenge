/*short and int: -32,767 to 32,767
**unsigned short int and unsigned int: 0 to 65,535
**long int: -2,147,483,647 to 2,147,483,647
**unsigned long int: 0 to 4,294,967,295
**long long int: -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
**unsigned long long int: 0 to 18,446,744,073,709,551,615.*/

#pragma optimize('O3')
#include <bits/stdc++.h>
#define lli long long int
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define pf push_front
#define MOD 1000000007
#define F first
#define S second
#define inf INT_MAX
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define i_am_iron_man ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> in, low, parent;

set <int> artPoints;

int timer;

void addEdge(int a, int b)
{
	graph[b].pb(a);
	graph[a].pb(b);
}

void dfs(int node)
{
	visited[node] = true;
	in[node] = low[node] = timer++;
	int subTrees = 0;
	for(int i: graph[node])
	{
		if(visited[i])
		{
			if(i == parent[node])
				continue;
			else
				low[node] = min(low[node], in[i]);
		}
		else
		{
			parent[i] = node;
			dfs(i);
			if(low[i] > in[node] and parent[i] != -1)
				artPoints.insert(i);
			++children;
		}
	}
	if(parent[node] == -1 and children > 1)
		artPoints.insert(i);
}

int main()
{
	i_am_iron_man
	int test;
	cin >> test;
	while(test--)
	{
		int n, e, a, b;
		cin >> n >> e;
		graph.assign(n, vector<int>());
		visited.assign(n, false);
		in.assign(n, -1);
		low.assign(n, -1);
		parent.assign(n, -1);
		while(e--)
		{
			cin >> a >> b;
			addEdge(--a, --b);
		}
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				parent[i] = -1;
				dfs(i);
			}
		}
	}
	return 0;
}