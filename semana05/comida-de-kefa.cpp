#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> satisfacoes(18);
vector<vector<ll>> regras(18, vector<ll>(19, 0));
ll nPratos, nComer, nRegras;

vector<vector<ll>> mem(19, vector<ll>(1 << 18, numeric_limits<ll>::max()));

ll sol(int nComidos, int ultimo, ll bits) {
    if (nComidos == nComer) {
        mem[ultimo][bits] = 0;
        return 0;
    }
    if (mem[ultimo][bits] != numeric_limits<ll>::max()) {
        return mem[ultimo][bits];
    }
    ll maxValue = 0;
    for (int i = 0; i < nPratos; i++) {
        if (!((bits >> i) & 1)) {
            maxValue = max(maxValue, satisfacoes[i] + regras[i][ultimo] + sol(nComidos + 1, i, bits | (1<<i)));
        }
    }

    mem[ultimo][bits] = maxValue;
    return maxValue;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> nPratos >> nComer >> nRegras;

    for (int i = 0; i < nPratos; i++) {
        cin >> satisfacoes[i];
    }

    ll x, y, c;

    for (int i = 0; i < nRegras; i++) {
        cin >> x >> y >> c;
        regras[x-1][y-1] = c;
    }

    cout << sol(0, nPratos, 0) << "\n";    
}