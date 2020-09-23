#include <bits/stdc++.h>

#define pb push_back
#define inf INT_MAX

using namespace std;

vector<pair <int, int>> graph[10005];

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    while(m--) {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    //Max heap priority queue declaration
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector <int> dist (n+1, inf);
    vector <int> parent (n+1, 1);
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        int curr = pq.top().second; //current node
        int curr_d = pq.top().first; //current node distance
        pq.pop();
        for(auto i: graph[curr]) {
            if(curr_d + i.second < dist[i.first]) {
                parent[i.first] = curr;
                dist[i.first] = curr_d + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
    if(dist[n] == inf)
        cout << -1 << endl;
    else {
    vector <int> res ;
    for(int i = n; i != 1; i = parent[i])
        res.pb(i);
    res.pb(1);
    reverse(res.begin(), res.end());
    for(auto i: res)
        cout << i << " ";
    cout << endl;
}
//    for(auto i: dist)
//        cout << i << " ";
 //   cout << endl;
}





















//
//int main()
//{
//    string test = "1.34.35.63";
//    test.erase(remove(test.begin(), test.end(), '.'), test.end());
//    cout << test << endl;
//    int laudaMera = stoi(test);
//    cout << laudaMera << endl;
//    cout << INT_MAX << endl;
//    cout << INT_MIN << endl;
//    cout << '8' - '0' << " " << '9' - '0' << " " << '5' - '0' << endl;
//    string yo = "3453";
//    int fuckMeDaddy = 345;
//    cout << to_string(fuckMeDaddy) << endl;
//    return 0;
//}
