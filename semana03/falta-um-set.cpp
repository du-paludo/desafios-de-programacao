#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    ll a;
    vector<ll> arr(n);
  
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
    }

    sort(arr.begin(), arr.end());

    ll oldR;
    ll r;
    vector<ll> rArr;
    set<ll> sol;
    int differentRatio = -1;

    for (int i = n-1; i > 0; i--) {
        r = arr[i]/arr[i-1];
        rArr.push_back(r);
    }

    // for (int i = 0; i < size(rArr); i++) {
    //     cout << rArr[i] << ' ';
    // }
    // cout << '\n';

    for (int i = 1; i < size(rArr); i++) {
        if (rArr[i] != rArr[i-1]) {
            differentRatio = i;
        }
    }

    if (differentRatio == -1) {
        if (arr[0] % r == 0) {
            sol.insert(arr[0] / r);
        }
        sol.insert(arr[n-1] * r);
    } else {
        sol.insert(arr[differentRatio-1] * r);
    }

    for (auto it = sol.begin(); it != sol.end(); it++) {
        cout << *it << '\n';
    }
}