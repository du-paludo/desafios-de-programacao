#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    string x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        int xValue = int(x.back());
        int yValue = int(y.back());
        if ((xValue + yValue) % 2 == 0) {
            cout << "PARCEIROS\n";
        } else {
            cout << "NAO PARCEIROS\n";
        }
    }
}