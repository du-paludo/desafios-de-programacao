#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    string value;
    set<string> sequence;
    for (int i = 0; i < n; i++) {
        cin >> value;
        sequence.insert(value);
    }
}