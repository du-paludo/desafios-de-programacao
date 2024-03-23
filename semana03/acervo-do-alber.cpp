#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> restrictions;

void permute(int* currentPermutation, int* remainingElements, int l, int n) {
    bool shouldStop = false;
    
    if (l == n) {
        for (int i = 0; i < n-1; i++) {
            cout << currentPermutation[i] << ' ';
        }
        cout << currentPermutation[n-1] << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            if (remainingElements[i] == 0) {
                shouldStop = false;
                remainingElements[i] = 1;
                currentPermutation[l] = i+1;
                for (pair<int, int> restriction : restrictions) {
                    if (currentPermutation[l] == restriction.second && remainingElements[restriction.first-1] == 0) {
                        shouldStop = true;
                    }
                    if (currentPermutation[l] == restriction.first && remainingElements[restriction.second-1] == 1) {
                        shouldStop = true;
                    }
                }
                if (!shouldStop) {
                    permute(currentPermutation, remainingElements, l+1, n);
                }
                remainingElements[i] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, c;
    cin >> n >> c;
    int a, b;
    int* currentPermutation = (int*) malloc(n * sizeof(int));
    int* remainingElements = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < c; i++) {
        cin >> a >> b;
        restrictions.push_back(make_pair(a, b));
    }

    for (int i = 0; i < n; i++) {
        remainingElements[i] = 0;
    }

    permute(currentPermutation, remainingElements, 0, n);
}