#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> dist(1e6, numeric_limits<int>::max());
vector<vector<int>> adj(1e6);
vector<int> parent(1e6, -1);
int n, m;

void shortestPath(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) { continue; }

        for (int v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vector<char> savePath(int start, int end) {
    vector<char> path;

    for (int v = end; v != start; v = parent[v]) {
        if (parent[v] == v-1) {
            path.push_back('R');
        } else if (parent[v] == v+1) {
            path.push_back('L');
        } else if (parent[v] == v-m) {
            path.push_back('D');
        } else if (parent[v] == v+m) {
            path.push_back('U');
        }
    }

    return path;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    // Vetor de adjacências
    // Cada item do vetor é uma casa do mapa
    // Cada casa contém um vetor de vizinhos compatíveis
    
    vector<char> map(n*m);

    char c;
    int start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == 'A') { start = i*m + j; }
            else if (c == 'B') { end = i*m + j; }
            map[i*m + j] = c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= 1 && map[(i-1)*m+j] != '#') {
                adj[i*m+j].push_back((i-1)*m+j);
                adj[(i-1)*m+j].push_back(i*m+j);
            }
            if (j >= 1 && map[i*m+(j-1)] != '#') {
                adj[i*m+j].push_back(i*m+(j-1));
                adj[i*m+(j-1)].push_back(i*m+j);
            }
        }
    }

    shortestPath(start, end);

    if (dist[end] == numeric_limits<int>::max()) {
        cout << "NO\n";
    } else {
        vector<char> path = savePath(start, end);
        cout << "YES\n" << path.size() << '\n';
        for (int i = path.size()-1; i >= 0; i--) {
            cout << path[i];
        }
        cout << '\n';
    }
}