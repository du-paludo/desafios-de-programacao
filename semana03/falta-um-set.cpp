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
    set<ll> rArr;
    map<ll, int> frequency;
    set<ll> sol;
    int smallestFrequency = 999;
    ll differentRatio = -1;

    for (int i = n-1; i > 0; i--) {
        r = arr[i]/arr[i-1];
        if (rArr.find(r) != rArr.end()) {
            frequency[r] += 1;
        } else {
            rArr.insert(r);
            frequency[r] = 1;
        }
    }

    for (auto it = rArr.begin(); it != rArr.end(); it++) {
        if (frequency[*it] < smallestFrequency) {
            smallestFrequency = frequency[*it];
            differentRatio = *it;
        }
    }

    int differentRatioIndex = -1;

    if (rArr.size() != 1) {
        for (int i = n-1; i > 0; i--) {
            if (arr[i] / arr[i-1] == differentRatio) {
                differentRatioIndex = i;
            } else {
                r = arr[i] / arr[i-1];
            }
        }
    } else {
        r = *rArr.begin();
    }

    if (differentRatioIndex == -1) {
        if (arr[0] % r == 0) {
            sol.insert(arr[0] / r);
        }
        sol.insert(arr[n-1] * r);
    } else {
        sol.insert(arr[differentRatioIndex-1] * r);
    }

    for (auto it = sol.begin(); it != sol.end(); it++) {
        cout << *it << '\n';
    }
}