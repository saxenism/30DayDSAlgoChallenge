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

struct edge
{
	int from;
	int to;
	int wt;
};

edge graph[100005];
int parent[100005], R[100005];

int find(int a)
{
	if(parent[a] < 0)
		return a;
	else
		return (parent[a] = find(parent[a]));
}

void union_fun(int x, int y)
{
	 x = find(x);
	 y = find(y);
	if(x != y)
	{
		if(R[x] > R[y])
		{
			parent[y] = x;
			R[x] += R[y];
		}
		else
		{
			parent[x] = y;
			R[y] += R[x];
		}
	}
}

int main()
{
	i_am_iron_man
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		parent[i] = -1;
		R[i] = 1;
	}

	int sum = 0;

	for(int i = 1; i <= m; i++){
		cin >> graph[i].from >> graph[i].to >> graph[i].wt;
		if(find(graph[i].from) != find(graph[i].to))
		{
			union_fun(graph[i].from, graph[i].to);
			sum += graph[i].wt;
		}
	}

	cout << sum << endl;

	return 0;
}