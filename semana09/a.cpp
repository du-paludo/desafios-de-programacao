#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj(1e6);
vector<int> subtreeSize(1e6);
vector<bool> visited(1e6, false);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k, a, b;
    cin >> n >> m >> k;

    vector<vector<int>> edges;
    vector<vector<int>> brokenEdges;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        brokenEdges[a].push_back(b);
        brokenEdges[b].push_back(a);
    }

    int componentes = 1;
}