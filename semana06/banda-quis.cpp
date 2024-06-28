#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numIngressos, numFas, h, t;
    cin >> numIngressos >> numFas;

    multiset<int> precos;

    for (int i = 0; i < numIngressos; i++) {
        cin >> h;
        precos.insert(h);
    }

    for (int i = 0; i < numFas; i++) {
        cin >> t;
        auto it = precos.lower_bound(t);
        if (*it != t) {
            if (it == precos.begin()) {
                cout << "-1\n";
                continue;
            } else {
                it--;
            }
        }
        cout << *it << "\n";
        precos.erase(it);
    }
}