/*
Question Link:
https://www.spoj.com/problems/SUBMERGE/

Question:
ice City is built over a group of islands, with bridges connecting them. As anyone in Vice City knows, the biggest fear of vice-citiers is that some day the islands will submerge. The big problem with this is that once the islands submerge, some of the other islands could get disconnected. You have been hired by the mayor of Vice city to tell him how many islands, when submerged, will disconnect parts of Vice City. You should know that initially all the islands of the city are connected.
Input

The input will consist of a series of test cases. Each test case will start with the number N (1 ≤ N ≤ 10^4) of islands, and the number M of bridges (1 ≤ M ≤ 10^5). Following there will be M lines each describing a bridge. Each of these M lines will contain two integers Ui, Vi (1 ≤ Ui,Vi ≤ N), indicating that there is a bridge connecting islands Ui and Vi. The input ends with a case where N = M = 0.
Output

For each case on the input you must print a line indicating the number of islands that, when submerged, will disconnect parts of the city.

Sample Input:
3 3
1 2
2 3
1 3
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
0 0

Expected Output:
0 
1

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

vector<vector<int>> graph;
vector<bool> visited;
vector<int> in, low, parent;

int timer;

set<int> artPoints;

void addEdge(int a, int b)
{
	graph[a].pb(b);
	graph[b].pb(a);
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
			if(parent[node] == i)
				continue;
			else
				low[node] = min(low[node], in[i]);
		}
		else
		{
			parent[i] = node;
			dfs(i);
			subTrees++;
			low[node] = min(low[node], low[i]);
			if(in[node] <= low[i] and parent[node] != -1)
				artPoints.insert(node);
		}
	}
	if(parent[node] == -1 and subTrees > 1)
		artPoints.insert(node);
}

int main()
{
	i_am_iron_man
	while(1)
	{
		int n, m;
		cin >> n >> m;
		if(n == 0 and m == 0)
			break;
		graph.assign(n, vector<int>());
		visited.assign(n, false);
		in.assign(n, -1);
		low.assign(n, -1);
		parent.assign(n, -1);
		artPoints.clear();
		timer = 1;
		while(m--)
		{
			int a, b;
			cin >> a >> b;
			addEdge(--a, --b);
		}

		for(int i = 0; i < n; i++){
			if(!visited[i])
			{
				parent[i] = -1;
				dfs(i);
			}			
		}
			

		cout << artPoints.size() << endl;
	}
	return 0;
}