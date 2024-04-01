#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll x, y, a, b, c, val;
    // 0 - vermelha, 1 - verde, 2 - sem cor
    int type;
    cin >> x >> y >> a >> b >> c;

    multiset<pair<int, int>, greater<pair<int, int>>> applesArr;
    ll sum = 0;

    for (int i = 0; i < a; i++) {
        cin >> val;
        applesArr.insert(make_pair(val, 0));
    }

    for (int i = 0; i < b; i++) {
        cin >> val;
        applesArr.insert(make_pair(val, 1));
    }

    for (int i = 0; i < c; i++) {
        cin >> val;
        applesArr.insert(make_pair(val, 2));
    }

    ll credits = 0;
    for (auto it = applesArr.begin(); it != applesArr.end(); it++) {
        if (it->second == 0 && x > 0) {
            x--;
            sum += it->first;
        } else if (it->second == 1 && y > 0) {
            y--;
            sum += it->first;
        } else if (it->second == 2 && (x > 0 || y > 0)) {
            credits++;
            sum += it->first;
        }
        if (credits == x + y) {
            break;
        }
    }

    cout << sum << "\n";
}