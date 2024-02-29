#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int oldX;
    int newX;
    
    ll count = 0;
    cin >> oldX;

    for (int i = 0; i < n-1; i++) {
        cin >> newX;
        while (newX < oldX) {
            newX += 1;
            count += 1;
        }
        oldX = newX;
    }

    cout << count << '\n';
}