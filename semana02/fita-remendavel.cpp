#include <iostream>
#include <list>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    list<int> tape;
    auto it = tape.begin()++;
    char type;
    int positions, value;

    for (int i = 0; i < n; i++) {
        cin >> type;
        switch (type) {
            case 'm':
                cin >> positions;
                advance(it, positions);
                break;
            case 'i':
                cin >> positions >> value;
                it = tape.insert(it, positions, value);
                // it--;
                break;
            case 'd':
                it = tape.erase(it);
                break;
            case 'q':
                cout << *it << '\n';
                break;
        }
    }
}