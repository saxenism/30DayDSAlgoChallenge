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
vector<int> parent;
vector<int> low;
vector<int> in;

int timer;

void addEdge(int a, int b)
{
	graph[a].pb(b);
	graph[b].pb(a);
}

void detect_bridge(int node)
{
	visited[node] = true;
	in[node] = low[node] = timer;
	++timer;
	for(int i: graph[node])
	{
		parent[i] = node;
		if(visited[i]){
			if(i == parent[node])
				continue;
			else
				low[node] = min(low[node], in[i]);
		}
		else{
			detect_bridge(i);
            low[node] = min(low[node], low[i]);
			if(low[i] > in[node])
				cout << "Bridge exists between " << ++node << " and " << ++i << endl;
		}
	}
}

int main()
{
	int n, e;
	cin >> n >> e;
	graph.assign(n, vector<int>());
	visited.assign(n, false);
	parent.assign(n, -1);
	low.assign(n, 0);
	in.assign(n, 0);
	while(e--)
	{
		int a, b;
		cin >> a >> b;
		addEdge(--a, --b);
	}
	detect_bridge(0);
	return 0;
}
