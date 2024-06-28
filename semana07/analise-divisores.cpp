#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, x, k;
    cin >> n;

    vector<pair<ll, ll>> fatores;

    for (ll i = 0; i < n; i++) {
        cin >> x >> k;
        fatores.push_back(make_pair(x, k));
    }

    ll numDivisores = 1;
    for (auto it = fatores.begin(); it != fatores.end(); it++) {
        numDivisores *= (it->second + 1);
    }

    ll somaDivisores = 1;
    for (auto it = fatores.begin(); it != fatores.end(); it++) {
        ll power = 1; 
        ll somaParcelas = power;
        for (ll i = 0; i < it->second; i++) {
            power *= it->first;
            somaParcelas += power;
        }
        somaDivisores *= somaParcelas;
    }

    ll num = 1;
    for (auto it = fatores.begin(); it != fatores.end(); it++) {
        for (ll i = 0; i < it->second; i++) {
            num *= it->first;
        }
    }

    ll produtoDivisores = pow(num, numDivisores/2);

    cout << numDivisores << ' ' << somaDivisores << ' ' << produtoDivisores << '\n';
}