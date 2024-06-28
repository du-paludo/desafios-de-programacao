#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll numTiras, areaEsperada, comprimento, soma, area;
    double altura;
    cin >> numTiras >> areaEsperada;

    vector<ll> tiras;

    while (numTiras != 0 && areaEsperada != 0) {
        soma = 0, area = 0, altura = 0.0;

        for (int i = 0; i < numTiras; i++) {
            cin >> comprimento;
            tiras.push_back(comprimento);
            soma += comprimento;
        }
        tiras.push_back(0);
        sort(tiras.begin(), tiras.end(), greater<int>());

        if (soma == areaEsperada) {
            cout << ":D\n";
        } else if (areaEsperada > soma) {
            cout << "-.-\n";
        } else {
            for (int i = 0; i < numTiras; i++) {
                area += (tiras[i] - tiras[i+1]) * (i+1);

                if (area > areaEsperada) {
                    altura = double(tiras[i+1]) + double(area - areaEsperada)/double(i+1);
                    break;
                }

            }
            cout << fixed << setprecision(4) << altura << '\n';
        }
        tiras.clear();
        cin >> numTiras >> areaEsperada;
    }
}