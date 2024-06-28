#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int numCubos, tam;
    cin >> numCubos;

    multiset<int> torres;

    for (int i = 0; i < numCubos; i++) {
        cin >> tam;
        auto it = torres.upper_bound(tam);
        if (it != torres.end()) {
            torres.erase(it);
        }
        torres.insert(tam);
    }
    
    cout << torres.size() << '\n';
}