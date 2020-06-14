/*
Question Link:
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/description/

Question:
Monk is having a hard time teaching the standard students. He wants to divide the students into small groups so that he can conduct some fun-filled activities for them. But students also want their friends in the same group. So, if student A is a friend of student B, and student B is a friend of student C, then the students A,B and C must be in the same group, otherwise they will start crying. After dividing the students, he will choose a leader from each group who will lead their respective groups. Now he wants to know the number of ways he can choose the group leaders from all the groups. Print this answer modulo.
Note: Two ways A and B will be considered different if at least 1 person is a leader in group A, and is not a leader in group B, or vice-versa.
Input:
The first line consists of two integers N and M denoting the number of students and the number of relationships respectively. The next M lines consists of two integers u and v denoting that student u and student v are friends. u and v can never be equal and relationships are not repeated.

Output:
Print the answer modulo

in a single line.

Constraints:
1<= N <=10^5
1<= M <= 10^5
1<= u,v <= N

Sample Input:
5 4
1 2
2 3
1 3
4 5

Expected Output:
6
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
#define endl "\n"
#define S second
#define inf INT_MAX
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define i_am_iron_man ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int parent[100005];

int find(int a)
{
	while(parent[a] > 0)
		a = parent[a];
	return a;
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
	for(int i = 0; i < m; i++)
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
	// for(int i: parent)
	// 	cout << i << " ";
	// cout << endl;

	return 0;
}