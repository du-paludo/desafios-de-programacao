#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, h, p;
    cin >> n >> h;
    set<ll, greater<ll>> arr;
    map<ll, ll> lessThanElement;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> p;
        auto it = arr.begin();
        if (i >= h) {
            while (*it > p && it != arr.end()) {
                sum++;
                it++;
            }
        }
        arr.insert(p);

    }
    cout << sum << '\n';
}