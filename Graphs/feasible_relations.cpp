#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> cc_code;
int current_cc;

void addEdge(int u, int v)
{
    graph[v].push_back(u);
    graph[u].push_back(v);
}

void dfs(int node)
{
    visited[node] = true;
    cc_code[node] = current_cc;
    for(int i: graph[node])
        if(!visited[i])
            dfs(i);
}

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n, e;
        cin >> n >> e;
        graph.assign(n, vector<int>());
        visited.assign(n, false);
        cc_code.assign(n, -1);
        current_cc = 0;
        vector<pair<int, int>> check;
        while(e--)
        {
            int a, b;
            string s;
            cin >> a >> s >> b;
            if(s == "=")
                addEdge(--a, --b);
            else
            	check.push_back({--a, --b});
        }

        for(int i = 0; i < n; i++){
        	if(!visited[i]){
        		++current_cc;
        		dfs(i);
        	}
        }

        // for(int i: cc_code)
        // 	cout << i << " ";
        // cout << endl;

        bool flag = true;
        for(int i = 0; i < check.size(); i++)
        {
        	int a = check[i].first;
        	int b = check[i].second;
        	if(cc_code[a] == cc_code[b])
        	{
        		flag = false;
        		break;
        	}
        }

        if(!flag)
        	cout << "NO" << endl;
        else
        	cout << "YES" << endl;
    }
    return 0;
}
