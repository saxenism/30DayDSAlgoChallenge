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
vector<bool> visited(100001);
int cc_num = 0;
vector<int> cc_code(100001);
 
void addEdge(int u, int v)
{
	graph[u].eb(v);
	graph[v].eb(u);
}
 
void dfs(int node)
{
	visited[node] = true;
	cc_code[node] = cc_num;
	for(int i: graph[node])
		if(!visited[i])
			dfs(i);
}
 
int main()
{
	i_am_iron_man
	int n, e;
	cin >> n >> e;
	graph.assign(n, vector<int>());
	visited.assign(n, false);
	cc_code.assign(n, 0);
	vector<int> soldiers(n);
	for(int i = 0; i < n; i++)
		cin >> soldiers[i];
	while(e--)
	{
		int a, b;
		cin >> a >> b;
		addEdge(--a, --b);
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			++cc_num;
			dfs(i);
		}
	}
 
	int dead_num = 0;
	int injured = 0;
	vector<int> burn_index;
	burn_index.assign(cc_num, 0);
	for(int i = 0; i < cc_num; i++)
	{
		int max_sol = -1;
		for(int j = 0; j < n; j++)
		{
			if(cc_code[j] == i+1)
			{
				if(soldiers[j] > max_sol){
					max_sol = soldiers[j];
					burn_index[i] = j+1;
				}
				injured += soldiers[j];
			}
		}
		dead_num += max_sol;
		injured -= max_sol;
	}
	cout << dead_num << " " << injured << endl;
	sort(burn_index.begin(), burn_index.end());
	for(int i = 0; i < cc_num; i++)
		cout << burn_index[i] << " ";
	cout << endl;
	return 0;
}
