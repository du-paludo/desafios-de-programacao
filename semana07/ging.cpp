#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define M 1e9+7
#define MAX 1e4+1

ll modMul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ll modInverse(ll a, ll m) { return power(a, m - 2, m); }

ll modDiv(ll a, ll b, ll m) {
    a = a % m;
    ll inv = modInverse(b, m);
    return (inv * a) % m;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, c, a, b, num;
    cin >> n >> c;

    vector<ll> fat(MAX);

    fat[0] = 1;
    fat[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fat[i] = modMul(fat[i-1], i, M);
    }

    vector<pair<ll, ll>> colunas(n);

    for (int i = 0; i < n; i++) {
        cin >> num;
        colunas[i] = {num, n};
    }

    for (int i = 0; i < c; i++) {
        cin >> a >> b;
        colunas[b-1].second--;
    }

    ll qtde = 1;
    for (ll i = 0; i < n; i++) {
        qtde = modMul(qtde, modDiv(fat[colunas[i].first], fat[colunas[i].first - colunas[i].second], M), M);
    }

    cout << qtde << '\n';
}