#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(vector<ll>& bit, ll i, ll delta) {
    for (; i < bit.size(); i += i & (-i)) {
        bit[i] += delta;
    }
}

ll get(vector<ll>& bit, ll i) {
    ll ans = 0;
    for (; i > 0; i -= i & (-i)) {
        ans += bit[i];
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, q, a1, b1, a2, b2, op, d, p;
    char num;
    cin >> n;
    vector<ll> fita(n);
    for (ll i = 0; i < n; i++) {
        cin >> num;
        fita[i] = ll(num - '0');
    }

    vector<ll> bit(n+1, 0);
    for (long i = 1; i <= n; i++) {
        bit[i] += fita[i-1];
        ll r = i + (i & -i);
        if (r <= n) {
            bit[r] += bit[i];
        }
    }

    cin >> q; 
    for (ll i = 0; i < q; i++) {
        cin >> op;
        if (op == 3) {
            cin >> p >> d;
            add(bit, p, d - fita[p-1]);
            fita[p-1] = d;
            continue;
        }
        cin >> a1 >> b1 >> a2 >> b2 >> d;
        ll dr1 = (get(bit, b1) - get(bit, a1 - 1)) % 9;
        ll dr2 = (get(bit, b2) - get(bit, a2 - 1)) % 9;

        if (op == 1) {
            ll dr = (dr1 + dr2) % 9;
            if (d != dr) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else if (op == 2) {
            ll dr = (dr1 * dr2) % 9;
            if (d != dr) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}