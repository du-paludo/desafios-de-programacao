#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj(1e6);
vector<int> subtreeSize(1e6);
vector<bool> visited(1e6, false);
int n;

int getSubtreeSize(int u) {
    subtreeSize[u] = 1;
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) { continue; }
        subtreeSize[u] += getSubtreeSize(v);
    }
    return subtreeSize[u];
}

int getCentroid(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) { continue; }
        if (subtreeSize[v] * 2 > n) { return getCentroid(v); }
    }
    return u;
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
    
    getSubtreeSize(0);
    fill(visited.begin(), visited.end(), false);
    cout << '\n';

    for (int i = 0; i < n; i++) {
        cout << i+1 << ' ' << subtreeSize[i] << '\n';
    }

    cout << getCentroid(0) + 1 << '\n';
}