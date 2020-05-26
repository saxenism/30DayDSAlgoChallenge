/*
Question Link:
https://www.spoj.com/problems/PT07Y/

Question:
You are given an unweighted, undirected graph. Write a program to check if it's a tree topology.
Input

The first line of the input file contains two integers N and M --- number of nodes and number of edges in the graph (0 < N <= 10000, 0 <= M <= 20000). Next M lines contain M edges of that graph --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).
Output

Print YES if the given graph is a tree, otherwise print NO. 

Input:
3 2
1 2
2 3

Expected Output:
YES
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

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void dfs(lli node)
{
	visited[node] = true;
	for(lli i: graph[node])
		if(!visited[i])
			dfs(i);
}

int main()
{
	i_am_iron_man
	lli n, e;
	cin >> n >> e;
	lli edge = e;
	visited.assign(n, false);
	graph.assign(n, vector<lli>());
	while(edge--)
	{
		lli u, v;
		cin >> u >> v;
		addEdge(--u, --v);
	}
	lli connected_comp = 0;
	for(lli i = 0; i < n; i++){
		if(!visited[i]){
			++connected_comp;
			dfs(i);
		}
	}
	if(connected_comp == 1 && e == n-1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}