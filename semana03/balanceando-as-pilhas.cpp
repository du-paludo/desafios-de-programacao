#include <iostream>
using namespace std;
using ll = long long;

int smallestDiff = 999999999;

void bt(int* wArray, int i, int diff, int n) {
    if (i == n) {
        if (abs(diff) < smallestDiff) {
            smallestDiff = abs(diff);
        }
    } else {
        bt(wArray, i+1, diff + wArray[i], n);
        bt(wArray, i+1, diff - wArray[i], n);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, w;
    cin >> n;
    int* wArray = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        cin >> w;
        wArray[i] = w;
    }
    bt(wArray, 0, 0, n);
    free(wArray);
    cout << smallestDiff << '\n';
}