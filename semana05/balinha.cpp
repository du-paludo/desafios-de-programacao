#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll valor, x;

    const ll n = int(1e5);
    const ll moedas[5] = {1, 5, 10, 25, 50};

    ll mem[5][n];
    vector<ll> trocos;
    ll maxTroco = 0;

    while (cin >> valor) {
        if (valor > maxTroco) {
            maxTroco = valor;
        }
        trocos.push_back(valor);
    }

    // Formas de dar 0 reais de troco é 1;
    for (ll i = 0; i < 5; i++) {
        mem[i][0] = 1;
    }

    // Formas de dar troco usando apenas moedas de 1 centavo é 1;
    for (ll j = 0; j <= maxTroco; j++) {
        mem[0][j] = 1;
    }

    for (ll k = 1; k < 5; k++) {
        for (ll i = 1; i <= maxTroco; i++) {
            mem[k][i] = mem[k-1][i];
            if (i - moedas[k] >= 0) {
                mem[k][i] += mem[k][i - moedas[k]];
            }
        }
    }

    for (auto it = trocos.begin(); it != trocos.end(); it++) {
        cout << mem[4][*it] << '\n';
    }

    // for (int i = -1; i < 5; i++) {
    //     for (int j = 0; j <= maxTroco; j++) {
    //         if (i == -1) {
    //             printf("%2d ", j);
    //         } else {
    //             printf("%2d ", mem[i][j]);
    //         }
    //     }
    //     printf("\n");
    // }
}