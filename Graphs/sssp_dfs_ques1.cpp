/*
Link to Question:
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/submissions/

Question:
There are N countries {1,2,3,4....N} and N-1 roads(i.e depicting a tree)

Bishu lives in the Country 1 so this can be considered as the root of the tree.

Now there are Q girls who lives in various countries (not equal to 1) .

All of them want to propose Bishu.But Bishu has some condition.

He will accept the proposal of the girl who lives at minimum distance from his country.

Now the distance between two countries is the number of roads between them.

If two or more girls are at the same minimum distance then he will accept the proposal of the girl who lives in a country with minimum id.

No two girls are at same country.

Input: First line consists of N,i.e number of countries Next N-1 lines follow the type u v which denotes there is a road between u and v. Next line consists of Q Next Q lines consists of x where the girls live.

Output: Print the id of the country of the girl who will be accepted.

Help Him!!!!!

contraints: 2<=N<=1000 1<=u,v<=N 1<=Q<=(N-1)

Input:
6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4

Expected Output:
3

*/

#include <bits/stdc++.h>

#define lli long long int
#define endl "\n"
#define pb push_back
#define i_am_iron_man ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector <vector<lli>> graph;
vector <lli> dist;
vector <bool> visited;
vector <bool> girls;

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void dfs(lli node)
{
	visited[node] = true;
	for(lli i: graph[node])
	{
		if(!visited[i])
		{
			dist[i] = dist[node] + 1;
			dfs(i);
		}
	}
}

int main()
{
	i_am_iron_man
	lli n;
	cin >> n;
	lli e = n-1;
	visited.assign(n, false);
	dist.assign(n, 0);
	graph.assign(n, vector<lli>());
	while(e--)
	{
		lli u, v;
		cin >> u >> v;
		addEdge(--u, --v);
	}
	lli q;
	cin >> q;
	girls.assign(n, false);
	while(q--)
	{
		lli girl_node;
		cin >> girl_node;
		girls[--girl_node] = true;
	}
	lli source = 1;
	--source;
	dfs(source);
	sort(dist.begin(), dist.end());
	for(lli i = 0; i < n; i++){
		if(girls[i] == true){
            cout << i+1 << endl;
            break;
		}
	}

	return 0;
}
