#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, c, k, u, v, p, t;
    cin >> n >> m >> c >> k;

    vector<vector<pair<int, int>>> edges(n);
    vector<int> soma(c);

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        if (u == v + 1 && u < c) {
            soma[v] = p;
        } else if (v == u + 1 && v < c) {
            soma[u] = p;
        }
        edges[u].push_back({v, p});
        edges[v].push_back({u, p});
    }
    
    for (int i = c-2; i >= 0; i--) {
        soma[i] += soma[i+1];
    } 

    vector<int> dist(n, numeric_limits<int>::max());
    vector<int> vis(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    
    // Cidade de saída
    dist[k] = 0;
    q.push({0, k});

    while (!q.empty()) {
        auto [custoAtual, u] = q.top(); q.pop();
        if (vis[u]) { continue; }
        vis[u] = true;
        // Para cada vizinho de u
        for (auto [v, w] : edges[u]) {
            // Se o vizinho for menor que c, sua distância é a soma da distância atual + a soma até o destino
            if (v < c) {
                if (dist[u] + w + soma[v] < dist[v]) {
                    dist[v] = dist[u] + w + soma[v];
                }
            } else {
                if (dist[v] > dist[u]+w) {
                    dist[v] = dist[u]+w;
                    q.push({dist[v], v});
                }
            }
        }
    }

    int minDist = numeric_limits<int>::max();
    for (int i = 0; i < c; i++) {
        if (dist[i] < minDist) {
            minDist = dist[i];
        }
    }

    cout << minDist << '\n';
}