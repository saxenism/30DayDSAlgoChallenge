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

vector<vector<lli>> graph;
vector<bool> visited;
vector<lli> subSize;

void addEdge(lli u, lli v)
{
	graph[u].eb(v);
	graph[v].eb(u);
}

lli dfs(lli node)
{
	visited[node] = true;
	lli currSize = 1;
	for(lli i: graph[node])
		if(!visited[i]){
			currSize += dfs(i);
		}
	subSize[node] = currSize;
	return currSize;
}

int main()
{
	i_am_iron_man
	lli test;
	cin >> test;
	while(test--)
	{
		lli n, e;
		cin >> n >> e;
		graph.assign(n, vector<lli>());
		visited.assign(n, false);
		subSize.assign(n, 1);
		while(e--)
		{
			lli u, v;
			cin >> u >> v;
			addEdge(--u, --v);
		}
		lli source = 1; //We'll assume that the tree is rooted here.
		--source;
		dfs(source);
		for(lli i: subSize)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}