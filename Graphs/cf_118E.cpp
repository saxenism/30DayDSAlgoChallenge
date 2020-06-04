/*short and int: -32,767 to 32,767
**unsigned short int and unsigned int: 0 to 65,535
**long int: -2,147,483,647 to 2,147,483,647
**unsigned long int: 0 to 4,294,967,295
**long long int: -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
**unsigned long long int: 0 to 18,446,744,073,709,551,615.*/

#pragma optimize('O3')
#include <bits/stdc++.h>
#define lli long long int
#define pii pair<lli, lli>
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
vector<lli> in, low;
vector<pii> edgeList;

int timer;
bool hasBridge = false;

void addEdge(lli a, lli b)
{
    graph[a].pb(b);
    graph[b].pb(a);
}

void dfs(lli node, lli parent)
{
    visited[node] = true;
    in[node] = low[node] = timer++;
    for(lli i: graph[node])
    {
        if(visited[i]){
            if(parent == i)
                continue;
            else{
                low[node] = min(low[node], in[i]);
                if(in[node] > in[i])
                    edgeList.pb({node, i});
            }
        }
        else {
            dfs(i, node);
            low[node] = min(low[node], low[i]);
            if(low[i] > in[node]) {
                hasBridge = true;
                return;
            }
            edgeList.pb({node, i});
        }
    }
}

int main()
{
    i_am_iron_man
    lli n, e, a, b;
    cin >> n >> e;
    graph.assign(n, vector<lli>());
    visited.assign(n, false);
    in.assign(n, 0);
    low.assign(n, 0);
    //parent.assign(n, 0);
    //edgeList.assign(e, {0,0});
    edgeList.reserve(e);
    while(e--)
    {
        cin >> a >> b;
        addEdge(--a, --b);
    }
    dfs(0, -1);
    if(hasBridge)
        cout << 0 << endl;
    else{
        for(auto i: edgeList)
            cout << ++i.first << " " << ++i.second << endl;
    }
    return 0;
}
