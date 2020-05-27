/*
Link to question:
https://www.spoj.com/problems/BUGLIFE/

Question:
Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs.
Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.
Input
The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.
Output
The output for every scenario is a line containing “Scenario #i:”, where i is the number of the scenario starting at 1, followed by one line saying either “No suspicious bugs found!” if the experiment is consistent with his assumption about the bugs’ sexual behavior, or “Suspicious bugs found!” if Professor Hopper’s assumption is definitely wrong.

Sample Input:
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4

Expected Output:
Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found!

Tip:
Whereas it was important to check for bi-partite graph, don't forget the case of disconnected components. Bugs of a disconnected component may lead to suspicion.
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
vector<bool> bulb;

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

void dfs(lli node)
{
	visited[node] = true;
	cout << node << " ";
	for(lli i: graph[node])
		if(!visited[i])
			dfs(i);
}

bool bi_partite_dfs(lli node, bool light)
{
	visited[node] = true;
	bulb[node] = light;
	for(lli i: graph[node])
	{
		if(!visited[i]){
			if(!bi_partite_dfs(i, !light)){
				return false;
			}
		}
		else{
			if(bulb[node] == bulb[i]){
				return false;
			}
		}
	}
	return true;
}
int main()
{
	i_am_iron_man
	lli test;
	cin >> test;
	for(lli t = 1; t <= test; t++)
	{
		lli n, e;
		cin >> n >> e;
		graph.assign(n, vector<lli>());
		visited.assign(n, false);
		bulb.assign(n, false);
		while(e--)
		{
			lli u, v;
			cin >> u >> v;
			addEdge(--u, --v);
		}
		lli source = 1;
		--source;
		bulb[source] = true;
		bool res = bi_partite_dfs(source, bulb[source]);
		for(lli i = 1; i < n; i++){
			if(!visited[i]){
				res = res & bi_partite_dfs(i, true);
			}
		}
		cout << "Scenario #" << t << ":" << endl;
		if(res){
			cout << "No suspicious bugs found!" << endl;
		} 
		else {
			cout << "Suspicious bugs found!" << endl;
		}
	}
	return 0;
}
