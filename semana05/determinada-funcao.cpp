#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> values;

ll f(ll k) {
    ll a, b;
    if (k == 0) {
        return 1;
    }
    if (values.find(k/2) != values.end()) {
        a = values[k/2];
    } else {
        a = f(k/2);
        values[k/2] = a;
    }
    if (values.find(k/3) != values.end()) {
        b = values[k/3];
    } else {
        b = f(k/3);
        values[k/3] = b;
    }
    return a + b;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    ll result = f(n);
    cout << result << '\n';
}