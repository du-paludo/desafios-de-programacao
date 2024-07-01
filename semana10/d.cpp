#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 15;
const ll MOD = 1e9 + 7;

#define NEUTRAL 1
#define OP(X, Y) ((X) * (Y) % MOD)

vector<ll> t(4 * N, NEUTRAL), lazy(4 * N, 1);

void push(int ti, int tl, int tm, int tr) {
    if (lazy[ti] != 1) {
        t[ti * 2] = t[ti * 2] * lazy[ti] % MOD;
        lazy[ti * 2] = lazy[ti * 2] * lazy[ti] % MOD;
        t[ti * 2 + 1] = t[ti * 2 + 1] * lazy[ti] % MOD;
        lazy[ti * 2 + 1] = lazy[ti * 2 + 1] * lazy[ti] % MOD;
        lazy[ti] = 1;
    }
}

void set_value(int pos, int new_val, int ti = 1, int tl = 1, int tr = N) {
    if (tl == tr) {
        t[ti] = new_val;
        return;
    }
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    if (pos <= tm) set_value(pos, new_val, ti * 2, tl, tm);
    else set_value(pos, new_val, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

ll mul_inclusive(int l, int r, int ti = 1, int tl = 1, int tr = N) {
    if (l > r) return NEUTRAL;
    if (l <= tl && tr <= r) return t[ti];
    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    return OP(mul_inclusive(l, min(r, tm), ti * 2, tl, tm),
              mul_inclusive(max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr));
}

void build(vector<int>& src, int ti = 1, int tl = 1, int tr = N) {
    if (tl == tr) {
        if (tl < src.size()) t[ti] = src[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q, a, b, x;
    char op;
    cin >> n >> q;

    vector<int> src(n + 1);

    for (int i = 1; i <= n; i++) cin >> src[i];
    build(src);

    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == 'A') {
            cin >> a >> x;
            set_value(a, x);
        } else if (op == 'B') {
            cin >> a >> b;
            x = mul_inclusive(a, b);
            if (x > 0) {
                cout << '+';
            }
            else if (x < 0) {
                cout << '-';
            }
            else {
                cout << '0';
            }
        }
    }
    cout << '\n';
}