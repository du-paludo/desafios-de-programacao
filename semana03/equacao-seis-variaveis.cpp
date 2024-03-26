#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solutionCount = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, s;
    cin >> n;
    set<int> S;
    for (int i = 0; i < n; i++) {
        cin >> s;
        S.insert(s);
    }

    for (auto d = S.begin(); d != S.end(); d++) {
        if (*d == 0) {
            continue;
        }
        for (auto a = S.begin(); a != S.end(); a++) {
            for (auto b = S.begin(); b != S.end(); b++) {
                for (auto c = S.begin(); c != S.end(); c++) {
                    if ((*a * *b + *c) % *d != 0) {
                        continue;
                    }
                    for (auto e = S.begin(); e != S.end(); e++) {
                        if (S.find((*a * *b + *c) / *d - *e) != S.end()) {
                            solutionCount++;
                        }
                    }
                }
            }
        }
    }

    cout << solutionCount << "\n";
}