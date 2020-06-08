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

int n, m;
bool visited[1005][1005];
int grid[1005][1005];

bool isValid(int x, int y)
{
	if(x < 1 or x > n or y < 1 or y > m)
		return false;
	if(visited[x][y] == true or grid[x][y] == 0)
		return false;

	return true;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
	visited[x][y] = true;

	for(int i = 0; i < 4; i++)
		if(isValid((x+dx[i]), (y+dy[i])))
			dfs((x+dx[i]), (y+dy[i]));
}

int main()
{
	i_am_iron_man
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> grid[i][j];

	int connected_component = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(visited[i][j] == false and grid[i][j] == 1)
			{
				++connected_component;
				dfs(i, j);
			}

	cout << "Number of Connected Components: " <<connected_component << endl;

	return 0;
}