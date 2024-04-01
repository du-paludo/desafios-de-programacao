#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    ll size;
    vector<ll> sizeArr;

    ll leftMiddleIndex = floor(double(n/2));
    ll rightMiddleIndex = ceil(double(n/2));

    for (int i = 0; i < n; i++) {
        cin >> size;
        sizeArr.push_back(size);
    }

    sort(sizeArr.begin(), sizeArr.end());
    ll leftMiddleValue = sizeArr[leftMiddleIndex];
    ll rightMiddleValue = sizeArr[rightMiddleIndex];

    ll leftCost = 0;
    ll rightCost = 0;

    for (int i = 0; i < n; i++) {
        leftCost += abs(sizeArr[i] - leftMiddleValue);
        rightCost += abs(sizeArr[i] - rightMiddleValue);
    }

    cout << min(leftCost, rightCost) << '\n';
}