#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solutionCount = 0;

// void bt(vector<int> S, vector<int> v, int i, int n) {
//     if (i == 6) {
//         for (int k = 0; k < 6; k++) {
//                 cout << v[k] << " ";
//             }
//         cout << '\n';
//         if ((v[5] + v[4]) * v[3] == v[0]*v[1] + v[2]) {
//             solutionCount++;
//         }
//     } else {
//         for (int j = 0; j < n; j++) {
//             v[i] = S[j];
//             if (i >= 3 && v[3] == 0) {
//                 return;
//             }
//             bt(S, v, i + 1, n);
//         }
//     }
// }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, s;
    cin >> n;
    vector<int> S;
    for (int i = 0; i < n; i++) {
        cin >> s;
        S.push_back(s);
    }

    for (int d = 0; d < n; d++) {
        if (S[d] == 0) {
            continue;
        }
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                for (int c = 0; c < n; c++) {
                    if ((S[a] * S[b] + S[c]) % S[d] != 0) {
                        continue;
                    }
                    for (int e = 0; e < n; e++) {
                        for (int f = 0; f < n; f++) {
                            if ((S[f] + S[e]) * S[d] == S[a]*S[b] + S[c]) {
                                solutionCount++;
                            }
                        }
                    }
                }
            }
        }
    }

    // bt(S, v, 0, n);
    cout << solutionCount << "\n";
}