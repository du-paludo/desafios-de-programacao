#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(vector<int>& bit, int i, int delta) {
    for (; i < bit.size(); i += i & -i) {
        bit[i] += delta;
    }
}

int get(vector<int>& bit, int i) {
    int idx = 0;
    for (; i > 0; i -= i & -i) {
        idx += bit[i];
    }
    return idx;
}

int bs(vector<int>& bit, int a, int b, int x) {
    if (a > b) {
        return -1;
    }
    int m = a + (b-a)/2;
    int v = get(bit, m);
    if (v < x) {
        return bs(bit, m+1, b, x);
    }
    if (v == x && (m == 1 || x > get(bit, m-1))) {
        return m;
    }
    return bs(bit, a, m-1, x);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    
    vector<int> fita(n);
    for (int i = 0; i < n; i++) {
        cin >> fita[i];
    }

    vector<int> bit(n+1, 1);
    bit[0] = bit[1] = 0;
    
    for (int i = 1; i <= n; i++) {
        int p = i + (i & -i);
        if (p <= n) {
            bit[p] += bit[i];
        }
    }

    char op;
    int value;
    int index = 0;
    int debug = 0;
    for (int i = 0; i < q; i++) {
        cin >> op;
        switch (op) {
            case 'm':
                cin >> value;
                index += value;
                break;
            case 'd':
                add(bit, bs(bit, 1, n, index), -1);
                break;
            case 'q':
                cout << fita[bs(bit, 1, n, index) - 1] << '\n';
                break;
        }
    }
}