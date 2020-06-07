#include <bits/stdc++.h>

#define pb push_back

using namespace std;

vector<int> graph[100005];
vector<bool> visited;
vector<int> ans;
int in_deg[100005];

void buildGraph(int a, int b)
{
	graph[a].pb(b);
	in_deg[b]++;
}

bool kahn(int n)
{
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 1; i <= n; i++)
		if(in_deg[i] == 0)
			q.push(i);
			
	while(!q.empty())
	{
		int f = q.top();
		ans.push_back(f);
		
		q.pop();
		for(int i: graph[f])
		{
			in_deg[i]--;
			if(in_deg[i] == 0)
				q.push(i);
		}
	}
	
	return ans.size() == n;
}

int main()
{
	int n, e;
	cin >> n >> e;
	while(e--)
	{
		int a, b;
		cin >> a >> b;
		buildGraph(a, b);
	}
	if(kahn(n))
	{
		for(int i: ans)
			cout << i << " ";
		cout << endl;
	}
	else
		cout << "Sandro fails." << endl;
	return 0;
}