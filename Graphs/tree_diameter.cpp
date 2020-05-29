/*
Question Link:
https://www.spoj.com/problems/PT07Z/

Question:
 You are given an unweighted, undirected tree. Write a program to output the length of the longest path (from one node to another) in that tree. The length of a path in this case is number of edges we traverse from source to destination.
Input

The first line of the input file contains one integer N --- number of nodes in the tree (0 < N <= 10000). Next N-1 lines contain N-1 edges of that tree --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u, v <= N).
Output

Print the length of the longest path on one line. 

Sample Input:
3
1 2
2 3

Expected Output:
2
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
vector<lli> dist;

lli diaNode = -1;
lli maxDist = -1;

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void dfs(lli node)
{
	visited[node] = true;
	if(dist[node] > maxDist){
		maxDist = dist[node];
		diaNode = node;
	}

	for(lli i: graph[node])
		if(!visited[i]){
			dist[i] = dist[node] + 1;
			dfs(i);
		}
}

int main()
{
	i_am_iron_man
	lli n, e;
	cin >> n;
	e = n-1;
	graph.assign(n, vector<lli>());
	visited.assign(n, false);
	dist.assign(n, 0);
	while(e--)
	{
		lli u, v;
		cin >> u >> v;
		addEdge(--u, --v);
	}
	lli source = 1;
	--source;
	dfs(source);

	maxDist = -1;
	visited.assign(n, false);
	dist.assign(n, 0);
	dfs(diaNode);

	cout << maxDist << endl;

	return 0;
}