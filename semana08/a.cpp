#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj(1e6+1);
vector<bool> analisados(1e3+1, false);

void explore(int u) {
    analisados[u] = true;
    for (int v : adj[u]) {
        if (!analisados[v]) {
            explore(v);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (analisados[i]) {
            continue;
        }
        count++;
        explore(i);
    }

    cout << count << '\n';
}