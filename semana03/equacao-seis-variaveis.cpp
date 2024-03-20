#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, s;
    cin >> n;
    set<int> sArray;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sArray.insert(s);
    }
}