#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void bellman_ford(vector<tuple<ll, ll, ll>>& estradas, vector<ll>& dist, ll src, ll n) {
    dist[src] = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (auto e : estradas) {
            ll dist_u = dist[get<0>(e)];
            ll dist_v = dist[get<1>(e)];
            ll w = get<2>(e);
            if (dist_u != numeric_limits<ll>::max() && dist_v > dist_u + w) {
                dist[get<1>(e)] = dist_u + w;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, m, x, y, q;
    cin >> n;
    vector<ll> lotacoes(n);

    for (ll i = 0; i < n; i++) {
        cin >> lotacoes[i];
    }

    cin >> m;
    vector<tuple<ll, ll, ll>> estradas(m);
    for (ll i = 0; i < m; i++) {
        cin >> x >> y;
        estradas[i] = {x-1, y-1, lotacoes[y-1]-lotacoes[x-1]};
    }

    vector<ll> dist(n, numeric_limits<ll>::max());
    bellman_ford(estradas, dist, 0, n);

    cin >> q;
    ll value;
    for (ll i = 0; i < q; i++) {
        cin >> x;
        value = dist[x-1];
        if (value < 3 || value == numeric_limits<ll>::max()) {
            cout << "Não, Edsger...\n";
        } else {
            cout << dist[x-1] << '\n';
        }
    }
}