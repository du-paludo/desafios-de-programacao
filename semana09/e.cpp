#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int m = 0; m < n; m++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dist[u][m] != numeric_limits<int>::max() && dist[m][v] !=  numeric_limits<int>::max()) {
                    dist[u][v] = min(dist[u][v], dist[u][m] + dist[m][v]);
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, u, v, w;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if (dist[u][v] > w) {
            dist[v][u] = w;
            dist[u][v] = w;
        }
    }

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    floydWarshall(dist, n);
    int minMax = numeric_limits<int>::max();

    for (int i = 0; i < n; i++) {
        int maxLoc = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] > maxLoc) {
                maxLoc = dist[i][j];
            }
        }
        if (maxLoc < minMax) {
            minMax = maxLoc;
        }
    }

    cout << minMax << '\n';
}