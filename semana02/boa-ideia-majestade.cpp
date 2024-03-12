#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int height;
    char direction;
    vector<tuple<int, char, bool>> pairs;
    bool isPossible = true;

    for (int i = 0; i < n; i++) {
        cin >> height >> direction;
        pairs.push_back(make_tuple(height, direction, false));
    }

    for (auto it = pairs.begin(); it != pairs.end(); it++) {
        if (get<2>(*it) == true) {
            continue;
        }
        // cout << "firstIt " << get<0>(*it) << get<1>(*it) << '\n';
        auto secIt = it + 1;
        for (secIt; secIt != pairs.end(); secIt++) {
            // cout << "secIt " << get<0>(*secIt) << get<1>(*secIt) << '\n';
            if (get<0>(*it) == get<0>(*secIt) && get<1>(*it) == 'L' && get<1>(*secIt) == 'O' && get<2>(*secIt) == false) {
                get<2>(*it) = true;
                get<2>(*secIt) = true;
                break;
            }
            if (get<0>(*secIt) >= get<0>(*it)) {
                isPossible = false;
            }
        }

        if (!isPossible) {
            break;
        }
    }

    for (auto it = pairs.begin(); it != pairs.end(); it++) {
        if (get<2>(*it) == false) {
            isPossible = false;
            break;
        }
    }

    if (isPossible) {
        cout << 'S' << '\n';
    } else {
        cout << 'N' << '\n';
    }
}