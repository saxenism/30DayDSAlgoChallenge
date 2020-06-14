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

int parent[100005];

int find(int a)
{
	if(parent[a] < 0)
		return a;

	else
		return (parent[a] = find(parent[a]));
}

void union_fun(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if(x != y)
	{
		parent[x] += parent[y];
		parent[y] = x;
	}
}

int main()
{
	i_am_iron_man
	memset(parent, -1, sizeof(parent));
	int n, m;
	cin >> n >> m;
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		union_fun(a, b);
	}

	lli res = 1;

	for(int i = 1; i <= n; i++)
		if(parent[i] < 0)
			res = (res*abs(parent[i]))%MOD;

	cout << res << endl;

	return 0;
}