#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int nQuadrados, nLapis, comprimento;
vector<int> numeros;
vector<vector<int>> mem(10001, vector<int>(10001, 0));

ll sol(int i, int lapisRestantes) {
    if (lapisRestantes * comprimento + i >= nQuadrados) {
        return 0;
    }
    
    if (mem[i][lapisRestantes] != 0) {
        return mem[i][lapisRestantes];
    }

    if (lapisRestantes == 0) {
        int sum = 0;
        for (auto it = numeros.begin() + i; it != numeros.end(); it++) {
            sum += *it;
        }
        return mem[i][lapisRestantes] = sum;
    }

    return mem[i][lapisRestantes] = max(sol(i + comprimento, lapisRestantes - 1), numeros[i] + sol(i + 1, lapisRestantes));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> nQuadrados >> nLapis >> comprimento;

    int a;
    for (ll i = 0; i < nQuadrados; i++) {
        cin >> a;
        numeros.push_back(a);
    }

    cout << sol(0, nLapis) << '\n';
}