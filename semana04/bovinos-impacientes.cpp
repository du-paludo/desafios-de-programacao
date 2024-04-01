#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, l, d;
    cin >> n;

    multiset<int, greater<int>> possibleChoices;
    map<int, multiset<int, greater<int>>> times;
    ll biggestTime = 0;

    for (int i = 0; i < n; i++) {
        cin >> l >> d;
        times[d].insert(l);
        if (d > biggestTime) {
            biggestTime = d;
        }
    }

    ll qtde = 0;
    for (int i = biggestTime; i > 0; i--) {
        if (times.find(i) != times.end()) {
            for (auto it = times[i].begin(); it != times[i].end(); it++) {
                possibleChoices.insert(*it);   
            }
        }
        if (!possibleChoices.empty()) {
            qtde += *possibleChoices.begin();
            possibleChoices.erase(possibleChoices.begin());
        }
    }

    cout << qtde << '\n';
}