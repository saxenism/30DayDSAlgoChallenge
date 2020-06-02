    #include <bits/stdc++.h>
     
    using namespace std;
     
    vector <int> graph[100005];
    bool visited[100005];
    int dist[100005];
     
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
            for(int i = 0; i < graph[f].size(); i++)
            {
                int v = graph[f][i];
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    dist[v] = dist[f] + 1;
                }
            }
        }
    }
     
    int main()
    {
        int n, e, a, b, test;
        cin >> n >> e;
        while(e--)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
     
        cin >> test;
        while(test--)
        {
            memset(visited, 0, sizeof(visited));
            memset(dist, 0, sizeof(dist));
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