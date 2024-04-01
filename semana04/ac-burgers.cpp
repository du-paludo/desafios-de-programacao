#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, p, h, f, d, c;
    cin >> t;
    ll lucro;
    for (int i = 0; i < t; i++) {
        cin >> p >> h >> f >> d >> c;
        lucro = 0;
        if (d > c) {
            while (p > 1 && h > 0) {
                p -= 2;
                h--;
                lucro += d;
            }
            while (p > 1 && f > 0) {
                p -= 2;
                f--;
                lucro += c;
            }
        } else {
            while (p > 1 && f > 0) {
                p -= 2;
                f--;
                lucro += c;
            }
            while (p > 1 && h > 0) {
                p -= 2;
                h--;
                lucro += d;
            }
        }
        cout << lucro << '\n';
    }
}