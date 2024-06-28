#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<bool> crivo(n, true);

    for (int i = 2; i*i <= n; i++) {
        if (crivo[i]) {
            for (int j = i*i; j <= n; j += i) {
                crivo[j] = false;
            }
        }
    }

    int qtde = 0;
    for (int i = 2; i <= n/2; i++) {
        if (crivo[i] && crivo[n-i]) {
            qtde++;
        }
    }

    cout << qtde << '\n';
}