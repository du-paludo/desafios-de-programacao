#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define L (i*m + j-1)
#define R (i*m + j+1)
#define U ((i-1)*m + j)
#define D ((i+1)*m + j)

#define LU ((i-1)*m + j-1)
#define RU ((i-1)*m + j+1)
#define LD ((i+1)*m + j-1)
#define RD ((i+1)*m + j+1)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, t;
    cin >> n >> m >> t;
    
    vector<int> map(n*m);
    vector<int> adj(n*m, 0);

    int pixel;
    int start, end;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pixel;
            map[i*m + j] = pixel;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i*m + j] == 0) {
                count++;
                if (i >= 1) { adj[U]++; }
                if (j >= 1) { adj[L]++; }
                if (i < n-1) { adj[D]++; }
                if (j < m-1) { adj[R]++; }

                if (i >= 1 && j >= 1 && map[LU] == 1) { adj[LU]++; }
                if (i >= 1 && j < m-1 && map[RU] == 1) { adj[RU]++; }
                if (i < n-1 && j >= 1 && map[LD] == 1) { adj[LD]++; }
                if (i < n-1 && j < m-1 && map[RD] == 1) { adj[RD]++; }
            }
        }
    }

    vector<int> turnedZero;

    for (int k = 0; k < t; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << k << ' ' << i << ',' << j << " : " << adj[i*m+j].size() << '\n';
                if ((map[i*m+j] == 1 || map[i*m+j] == 2) && adj[i*m+j] >= 1) {
                    turnedZero.push_back(i*m+j);
                    count++;
                } else if (map[i*m+j] == 3 && adj[i*m+j] >= 2) {
                    turnedZero.push_back(i*m+j);
                    count++;
                } else if (map[i*m+j] == 4 && adj[i*m+j] >= 3) {
                    turnedZero.push_back(i*m+j);
                    count++;
                }
            }
        }
        for (int idx : turnedZero) {
            int i = idx/m;
            int j = idx % m;
            if (i >= 1) { adj[U]++; }
            if (j >= 1) { adj[L]++; }
            if (i < n-1) { adj[D]++; }
            if (j < m-1) { adj[R]++; }

            if (i >= 1 && j >= 1 && map[LU] == 1) { adj[LU]++; }
            if (i >= 1 && j < m-1 && map[RU] == 1) { adj[RU]++; }
            if (i < n-1 && j >= 1 && map[LD] == 1) { adj[LD]++; }
            if (i < n-1 && j < m-1 && map[RD] == 1) { adj[RD]++; }
        }
        for (auto it = turnedZero.begin(); it != turnedZero.end(); it++) {
            int i = *it/m;
            int j = *it % m;
            map[i*m + j] = 0;
        }
        turnedZero.clear();
    }

    cout << count << '\n';
}