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

vector<lli> primes;
vector<lli> graph[100005];
vector<bool> visited(100005);
vector<lli> dist(100005);

void addEdge(lli u, lli v)
{
	graph[u].pb(v);
	graph[v].pb(u);
}

bool isPrime(lli  n)
{
	if(n == 0 or n == 1)
		return false;
	for(lli i = 2; i*i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

bool isValid(lli a, lli b)
{
	lli count = 0;
	while(a != 0)
	{
		if(a%10 != b%10)
			++count;
		a/10;
		b/10;
	}
	if(count == 1)
		return true;
	else
		return false;
}

void buildGraph()
{
	for(lli i = 1000; i < 10000; i++)
		if(isPrime(i))
			primes.eb(i);

	for(lli i = 0; i < primes.size(); i++)
	{
		for(lli j = i+1; j < primes.size(); j++)
		{
			lli a = primes[i];
			lli b = primes[j];
			if(isValid(a, b))
				addEdge(a, b);
		}
	}

}

void bfs(lli source)
{
	queue<lli> q;
	q.push(source);
	visited[source] = true;
	dist[source] = 0;
	while(!q.empty())
	{
		lli f = q.front();
		q.pop();
		for(lli i: graph[f])
		{
			if(!visited[i])
			{
				dist[i] = dist[f] + 1;
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	i_am_iron_man
	lli test;
	lli a, b;
	cin >> test;
    buildGraph();
	while(test--)
	{
		cin >> a >> b;
		lli n = 100005;
        for(lli i = 1000; i < 10000; i++)
        {
            dist[i] = -1;
            visited[i] = false;
        }
        bfs(a);
		if(dist[b] == -1)
			cout << "Impossible" << endl;
		else
			cout << dist[b] << endl;
	}
	return 0;
}
