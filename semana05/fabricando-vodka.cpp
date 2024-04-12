#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, i, m, p, c, v;
    cin >> n >> i >> m >> p;
    vector<int> custosMan;
    vector<int> valorVenda;
    int mem[n][2];

    for (int j = 0; j < m; j++) {
        cin >> c;
        custosMan.push_back(c);
    }

    for (int j = 0; j < m; j++) {
        cin >> v;
        valorVenda.push_back(v);
    }

    // Mínimo
    mem[0][0] = 0;
    // Should sell
    mem[0][1] = 0;

    for (int j = 1; j < n; j++) {
        // mem[j] = max(mem[j-1]
    }
}