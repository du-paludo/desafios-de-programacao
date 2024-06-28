#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> adj(1e6);

pair<int, int> getLargestDistance(int u) {
    vector<int> dis(n, -1);

    queue<int> q;
    q.push(u);
    dis[u] = 0;

    while (!q.empty()) {
        int t = q.front();
        q.pop();
        
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) {
            int v = *it;
            
            if (dis[v] == -1) {
                q.push(v);
                dis[v] = dis[t] + 1;
            }
        }
    }

    int maxDis = 0;
    int index = u;
    for (int i = 0; i < n; i++) {
        if (dis[i] > maxDis) {
            maxDis = dis[i];
            index = i;
        }
    }

    return make_pair(maxDis, index);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int max = 0;
    auto endpoint = getLargestDistance(0);
    auto longestDistance = getLargestDistance(endpoint.second);

    cout << longestDistance.first << '\n';
}