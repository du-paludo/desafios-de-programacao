#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int qtde;
    int soma = 0;

    for (int i = 0; i < n; i++) {
        cin >> qtde;
        if (qtde > 10) {
            soma += qtde-10;
        }
    }

    cout << soma << '\n';
}