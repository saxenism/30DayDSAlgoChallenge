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
#define endl "\n"
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define i_am_iron_man ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<int> graph[100005];
vector<bool> visited;
int in_deg[100005];
vector<int> res;

void buildGraph(int a, int b)
{
	graph[a].pb(b);
	in_deg[b]++;
}

void kahn(int n)
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(in_deg[i] == 0)
			q.push(i);

	while(!q.empty())
	{
		int f = q.front();
		res.pb(f);

		q.pop();
		for(int i: graph[f])
		{
			in_deg[i]--;
			if(in_deg[i] == 0)
				q.push(i);
		} 
	}
}

int main()
{
	i_am_iron_man
	lli n, e;
	cin >> n >> e;
	while(e--)
	{
		int a, b;
		cin >> a >> b;
		buildGraph(a, b);
	}
	kahn(n);
	for(int i: res)
		cout << i << " ";
	cout << endl;
	return 0;
}