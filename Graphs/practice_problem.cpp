/*
Question Link:
https://www.codechef.com/problems/FIRESC

Question:


Chef has been constantly expanding his chain of restaurants. It was getting too difficult for him to manage the finances of so many businesses all by himself. So he has opened up a new accounts office and hired people to help him with this task. There are N people working in this building and each one works in a separate cabin. Chef employees are numbered by integers from 1 to N, inclusive. Chef wants to ensure the safety of his employees. He wants to have fire escapes in the building and wants to train the employees to use these by conducting mock drills.

Chef knows that the number of people working in his office can be very large. In order to avoid crowding of a common fire escape route during emergency, Chef has decided to build multiple fire escapes. For the safety of every employee, each cabin has a fire exit which is connected to one of the fire escape routes.

A lot of employees are friends with each other. The friendship is mutual. This means that if employee i is a friend of employee j then employee j is a friend of employee i as well. But friendship is NOT necessarily transitive. This means that if employee i is a friend of employee j AND employee j is a friend of employee k, then employee i and employee k need not necessarily be friends.

If two employees are friends, they do not want to escape through different routes.

This complicates the task for the Chef. As already mentioned, he wants to have the maximum number of fire escape routes to ensure maximum safety. Also, for every escape route, one of the employees using that route needs to be appointed as the fire drill captain. The captain will be responsible for conducting the mock drills and train all the employees using that route. Your task is simple. Given the number of employees and the friendship list, you need to tell the Chef the maximum number of fire escape routes that he can have in the building and the number of ways of selecting the captains for every route. Since the number of ways can be really large, output this value modulo 109 + 7.
Input

The first line of the input contains a single integer T, denoting the number of test cases. The description of T test cases follows. The first line of each test case contains two space-separated integers N and M, denoting the number of employees and the number of friendship relations, respectively. Each of the following M lines contains two space-separated integers i and j, denoting employee i and employee j are friends.
Output

For each test case, output a single line containing two space separated integers, denoting the maximum number of distinct fire escape routes that can be constructed and the number of ways of selecting the captains modulo 109 + 7.
Constraints

    1 ≤ T ≤ 5
    1 ≤ N ≤ 100000 (105)
    0 ≤ M ≤ 100000 (105)
    1 ≤ i, j ≤ N
    i ≠ j
    For any pair of employees i and j such that 1 ≤ i < j ≤ N, at most one pair among (i, j) and (j, i) will appear in the input

Example Input:
3
4 2
1 2
2 3
5 3
1 2
2 3
1 3
6 3
1 2
3 4
5 6

Expected Output:
2 3
3 3
3 8

*/

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

vector<vector<lli>> graph;
vector<bool> visited;

lli comp_size;

void addEdge(lli u, lli v)
{
	graph[u].eb(v);
	graph[v].eb(u);
}

void dfs(lli node)
{
	visited[node] = true;
	comp_size++;
	for(lli i: graph[node])
		if(!visited[i])
			dfs(i);
}

int main()
{
	i_am_iron_man
	lli test;
	cin >> test;
	while(test--)
	{
		lli n, e;
		cin >> n >> e;
		graph.assign(n, vector<lli>());
		visited.assign(n, false);
		while(e--)
		{
			lli u, v;
			cin >> u >> v;
			addEdge(--u, --v);
		}
		lli connected_comp = 0;
		lli leaders = 1;
		for(lli i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				++connected_comp;
				comp_size = 0;
				dfs(i);
				leaders = (leaders * comp_size) % MOD;
			}
		}
		cout << connected_comp << " " << leaders << endl;
	}
	return 0;
}