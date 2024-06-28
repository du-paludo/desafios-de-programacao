#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, num, den, divisaoInteira, temp;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> num >> den;
        vector<int> sol;

        if (num == 0) {
            cout << "[0]\n";
        } else if (num % den == 0) {
            cout << '[' << num/den << "]\n";
        } else {
            while (den != 1 && den != 0) {
                temp = den;
                sol.push_back(num/den);
                den = num % den;
                num = temp;
            }
            if (den == 1) {
                sol.push_back(num);
            }

            cout << '[' << sol[0] << ';';
            for (int i = 1; i < sol.size()-1; i++) {
                cout << sol[i] << ',';
            }
            cout << sol[sol.size()-1] << "]\n";
        }
    }
}