#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int a, b, c;
    vector<tuple<int, int, int>> pontos;

    int arr[n][3];

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        pontos.push_back(make_tuple(a, b, c));
    }

    arr[0][0] = get<0>(pontos[0]);
    arr[0][1] = get<1>(pontos[0]);
    arr[0][2] = get<2>(pontos[0]);

    for (int i = 1; i < n; i++) {
        arr[i][0] = get<0>(pontos[i]) + max(arr[i-1][1], arr[i-1][2]);
        arr[i][1] = get<1>(pontos[i]) + max(arr[i-1][0], arr[i-1][2]);
        arr[i][2] = get<2>(pontos[i]) + max(arr[i-1][0], arr[i-1][1]);
    }

    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (arr[n-1][i] > max) {
            max = arr[n-1][i];
        } 
    }
    cout << max << '\n';
}