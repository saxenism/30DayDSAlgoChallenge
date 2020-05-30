/*
Question Link:
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/description/?layout=old

Question:
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

Output:
Print the answer to each test case in a new line.

Sample Input:
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2

Output:
2
2
*/

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

void addEdge(lli u, lli v)
{
	graph[v].eb(u);
	graph[u].eb(v);
}

void bfs(lli node)
{
	queue<lli> q;
	q.push(node);
	visited[node] = true;
	while(!q.empty())
	{
		lli f = q.front();
		q.pop();
		for(lli i: graph[f])
		{
			if(!visited[i])
			{
				visited[i] = true;
				dist[i] = dist[f] + 1;
				q.push(i);
			}
		}
	}
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
		dist.assign(n, 0);
		while(e--)
		{
			lli u, v;
			cin >> u >> v;
			addEdge(--u, --v);
		}
		lli source = 1;
		--source;
		bfs(source);
		// for(lli i: dist)
		// 	cout << i << " ";
		// cout << endl;
		cout << dist[n-1] << endl;
	}

	return 0;
}