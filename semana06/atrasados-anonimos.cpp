#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void merge_sort(vector<ll> &arr, ll* swaps, int l, int r) {
    if (r - l <= 1) { return; }
    int mi = l + (r - l) / 2;
    merge_sort(arr, swaps, l, mi); merge_sort(arr, swaps, mi, r);
    vector<int> aux (r - l);
    int i = l, j = mi;
    for (int k = 0; k < r - l; k++) {
        if (i < mi && j < r) {
            if (!(arr[i] < arr[j])) { *swaps += mi - i; }
            if (arr[i] < arr[j]) { aux[k] = arr[i++]; }
            else { aux[k] = arr[j++]; }
        } else if (i < mi) { aux[k] = arr[i++]; }
        else { aux[k] = arr[j++]; }
    }
    copy(aux.begin(), aux.end(), arr.begin()+l);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, h, p;
    cin >> n >> h;

    vector<ll> arr(n);
    vector<ll> cpArr(h);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll allSwaps = 0;
    ll earlySwaps = 0;

    copy(arr.begin(), arr.begin()+h, cpArr.begin());

    merge_sort(arr, &allSwaps, 0, n);
    merge_sort(cpArr, &earlySwaps, 0, h);

    cout << (allSwaps - earlySwaps) << '\n';
}