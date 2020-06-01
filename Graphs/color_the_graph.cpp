/*
Question Link:
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/color-the-graph/

Question:
You are given a graph with N nodes and M undirected edges. This graph does not contain self loops and multiple edges between same pair of nodes.
You plan to give this to Monk for his birthday so you wish to colour it. You want to colour all the nodes of the graph in either red or blue colour such that each edge has endpoints of different colours.
As Monk loves red colour, you also want the number of nodes with red colour to be maximum.
Output the maximum number of red coloured nodes you can get in the graph after colouring every vertex under the given constraint. If no such colouring is possible output "NO" (without quotes).

Input:
First line contains T, denoting the number of test cases.
Description of input for each input follows.
First line contains two integers N and M, the number of nodes in the graph and the number of edges in the graph.
Next M lines follow each containing two integers U and V, denoting an undirected edge between them.

Output:
Output T lines each containing the answer for the
test case.

Sample Input:
1
3 2
1 2
2 3

Expected Output:
2
*/

#include <bits/stdc++.h>

#define lli long long int

using namespace std;

vector<vector<lli>> graph;
vector<bool> visited;
vector<bool> bulb;
lli c, C;

void addEdge(lli u, lli v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void dfs(lli node, bool light)
{
	visited[node] = true;
	c += light;
	C++;
	for(lli i: graph[node])
		if(!visited[i])
			dfs(i, !light);
}

bool check_bipartite(lli node, bool light)
{
	visited[node] = true;
	bulb[node] = light;

	for(lli i: graph[node])
	{
		if(!visited[i]){
			if(!check_bipartite(i, !light)){
				return false;
			}
		}
		else{
			if(bulb[node] == bulb[i])
				return false;
		}
	}
	return true;
}

int main()
{
	lli test;
	cin >> test;
	while(test--)
	{
		lli n, e;
		cin >> n >> e;
		bulb.assign(n, false);
		visited.assign(n,false);
		graph.assign(n, vector<lli>());
		while(e--)
		{
			lli u, v;
			cin >> u >> v;
			addEdge(--u, --v);
		}

		bool bi_res = true;
		for(lli i = 0; i < n; i++){
			if(!visited[i]){
				bi_res = bi_res and check_bipartite(i, true);
			}
		}

		visited.assign(n, false);
		lli res_nodes = 0;

		for(lli i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				c = 0;
				C = 0;
				dfs(i, false);
				res_nodes += max(c, C-c);
			}
		}

		if(bi_res){
			cout << res_nodes << endl;;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}