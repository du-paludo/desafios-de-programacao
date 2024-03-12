#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int number;
    set<int> v;

    for (int i = 0; i < n; i++) {
        cin >> number;
        v.erase(number-1);
        v.insert(number);
    }

    cout << v.size() << "\n";
}