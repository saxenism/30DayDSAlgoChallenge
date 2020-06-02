#include <bits/stdc++.h>

#define lli long long int

using namespace std;

//vector<int> graph[100005];
vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;

void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i: graph[f])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
                dist[i] = dist[f] + 1;
            }
        }
    }
}

int main()
{
    int n, e, test;
    cin >> n >> e;
    graph.assign(n+1, vector<int>());
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }

    cin >> test;
    while(test--)
    {
        visited.assign(n, false);
        dist.assign(n, 0);
        int a, b;
        cin >> a >> b;
        bfs(a);
        int ans = 0;
        for(int i = 0; i <= n; i++)
            if(dist[i] == b)
                ++ans;
        cout << ans << endl;
    }
    return 0;
}
