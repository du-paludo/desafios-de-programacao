#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    ll a;
    vector<ll> satisfactions;

    for (int i = 0; i < n; i++) {
        cin >> a;
        satisfactions.push_back(a);
    }

    ll x, y, c;
    vector<tuple<ll, ll, ll>> regras;

    for (int i = 0; i < k; i++) {
        cin >> x >> y >> c;
        regras.push_back(make_tuple(x, y, c));
    }

    // Número de pratos comidos por último prato comido
    ll mem[m][n];
    for (int i = 0; i < n; i++) {
        mem[0][i] = satisfactions[i];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mem[i][j] = mem[i-1][j] + satisfactions[j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mem[i][j] << ' ';
        }
        cout << '\n';
    }
}