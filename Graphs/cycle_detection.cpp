/*
Tutorial Name:
Cycle detection in graph using DFS

Tutorial Link:
https://www.youtube.com/watch?v=eCG3T1m7rFY&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=11

Input:
1
5 5
1 2
2 3
3 4
2 4
4 5

Expected Output:
Contains Cycle

Tip;
Works for both directed and undirected graphs.
We cannot leverage "the fact" that if e > n-1 then it will have cycles because it does not consider multiple connected components.
A Back Edge is an edge that connects a node to its ancestor(already visited node) which is not its parent.
So detecting a back edge is a deterministic test of cycle detection in graphs.
*/

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
vector<lli> parent;

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

bool detect_cycle(lli node)
{
	visited[node] = true;
	for(lli i: graph[node])
	{
		parent[i] = node;
		if(!visited[node]){
			if(detect_cycle(i))
				return true;
		}
		else{
			if(parent[i] != i)
				return true;
		}
	}
	return false;
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
		parent.assign(n, -1);
		while(e--)
		{
			lli u, v;
			cin >> u >> v;
			addEdge(--u, --v);
		}
		lli source = 1;
		--source;
		detect_cycle(source) ? cout << "Contains Cycle\n" : cout << "No cycle\n";
	}
	return 0;
}