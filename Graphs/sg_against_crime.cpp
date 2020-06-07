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
#define endl "\n"
#define inf INT_MAX
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define i_am_iron_man ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector <pair<int, int>> graph[100005];
bool visited[100005];
lli in[100005], low[100005], parent[100005];

lli yes[1000005];

lli timer;

void dfs(lli node)
{
    visited[node] = true;
    low[node] = in[node] = timer++;
    for(auto i: graph[node])
    {
        if(visited[i.F])
        {
            if(parent[node] == i.F)
                continue;
            else
                low[node] = min(low[node], in[i.F]);
        }
        else
        {
            parent[i.F] = node;
            dfs(i.F);
            low[node] = min(low[node], low[i.F]);
            if(in[node] < low[i.F]){
                yes[i.S] = 1;
            }
        }

    }
}

int main()
{
	i_am_iron_man
	lli n, e, q, a, b, c;
	cin >> n >> e >> q;
	memset(parent, -1, sizeof(parent));
   	while(e--)
	{
		cin >> a >> b >> c;
    	graph[a].pb({b, c});
    	graph[b].pb({a, c});
	}
	for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i);

    lli query;
    while(q--)
    {
        cin >> query;
        if(yes[query] == 1)
            cout  << "YES" << endl;
        else
            cout << "no" << endl;
    }
//    for(auto i: yes)
//        cout << i << " " ;
//    cout << endl;
//    cout << "****************" << endl;
//    for(auto i: graph[2])
//        cout << i.F << " " << i.S << endl;
 	return 0;
}
