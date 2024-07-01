#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 15;
#define NEUTRAL LLONG_MAX
#define FACTOR(sz) (sz)
#define OP(X, Y) (min(X, Y))

vector<ll> t(4 * N, NEUTRAL), lazy(4 * N, 0);

void push(int ti, int tl, int tm, int tr) {
    if (lazy[ti] != 0) {
        t[ti * 2] += lazy[ti];
        lazy[ti * 2] += lazy[ti];
        t[ti * 2 + 1] += lazy[ti];
        lazy[ti * 2 + 1] += lazy[ti];
        lazy[ti] = 0;
    }
}

void add_inclusive(int l, int r, int d,
    int ti = 1, int tl = 1, int tr = N) {
    if (l > r) { return; }
    if (l == tl && tr == r) {
        t[ti] += d;
        lazy[ti] += d;
        return;
    }
    int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    add_inclusive(l, min(r, tm), d, ti * 2, tl, tm);
    add_inclusive(max(l, tm + 1), r, d, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

ll min_inclusive(int l, int r,
    int ti = 1, int tl = 1, int tr = N) {
    if (l > r) { return NEUTRAL; }
    if (l <= tl && tr <= r) { return t[ti]; }
    int tm = (tl + tr) / 2; push(ti, tl, tm, tr);
    return OP(min_inclusive(l, min(r, tm), ti * 2, tl, tm),
              min_inclusive(max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr));
}

void build(vector<int>& src,
    int ti = 1, int tl = 1, int tr = N) {
    if (tl == tr) {
        if (tl < src.size()) { t[ti] = src[tl]; }
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

    int n, q, op, a, b, x;
    cin >> n >> q;

    vector<int> src(n + 1);

    for (int i = 1; i <= n; i++) { cin >> src[i]; }
    build(src);

    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b >> x;
            add_inclusive(a, b, x);
        }
        else if (op == 2) {
            cin >> a >> b;
            cout << min_inclusive(a, b) << '\n';
        }
    }
}