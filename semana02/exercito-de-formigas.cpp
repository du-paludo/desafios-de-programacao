#include <iostream>
#include <set>
#include <math.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    int l, n, p;
    for (int i = 0; i < t; i++) {
        cin >> l >> n;
        int minMiddleDist = l;
        int maxAntDist = 0;
        double middlePos = double(l)/double(2);
        double currentDist;
        for (int j = 0; j < n; j++) {
            cin >> p;
            currentDist = abs(middlePos - p);
            if (currentDist < minMiddleDist) {
                minMiddleDist = currentDist;
            }
            currentDist = max(p, l - p);
            if (currentDist > maxAntDist) {
                maxAntDist = currentDist;
            }
        }
        cout << int(floor(middlePos - minMiddleDist)) << ' ' << maxAntDist << '\n';
    }
}