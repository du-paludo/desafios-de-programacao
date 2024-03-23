#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void partitionSub(vector<bitset<30>>& sequence, int i, int n, int k, int subsetN, vector<vector<bitset<30>>>& v) {
    if (i >= n && subsetN == k) {
        for (int x = 0; x < v.size(); x++) {
            cout << "{";
            for (int y = 0; y < v[x].size(); i++) {
                cout << v[x][y];

                if (y == v[x].size() - 1) {
                    cout << " ";
                } else {
                    cout << ", ";
                }
            }
            if (x == v.size() - 1) {
                cout << "}";
            } else {
                cout << "}, ";
            }
        }
        cout << "\n";
        return;
    }


    for (int j = 0; j < k; j++) {
        if (v[j].size() > 0) {
            v[j].push_back(sequence[i]);
            partitionSub(sequence, i+1, n, k, subsetN, v);
            v[j].pop_back();
        } else {
            v[j].push_back(sequence[i]);
            partitionSub(sequence, i+1, n, k, subsetN + 1, v);
            v[j].pop_back();
        }
    }
}

void partAllSubsets(vector<bitset<30>>& sequence, int n) {
    // for (int k = 1; k <= n; k++) {
        vector<vector<bitset<30>>> v(2);
        partitionSub(sequence, 0, n, 2, 0, v);
    // }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    ll value;
    vector<bitset<30>> sequence;
    for (int i = 0; i < n; i++) {
        cin >> value;
        sequence.push_back(bitset<30>(value));
    }
    partAllSubsets(sequence, n);
}