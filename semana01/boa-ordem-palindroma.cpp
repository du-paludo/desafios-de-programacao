#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int alfabeto[26];
    string input;
    string str;
    int impar = -1;

    for (int i = 0; i < 26; i++) {
        alfabeto[i] = 0;
    }

    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        alfabeto[int(input[i])-65]++;
    }

    // for (int i = 0; i < 26; i++) {
    //     cout << char(i+65) << ": " << alfabeto[i] << "\n";
    // }

    for (int i = 0; i < 26; i++) {
        if (alfabeto[i] % 2 == 0) {
            for (int j = 0; j < alfabeto[i]/2; j++) {
                str += char(i + 65);
            }
            alfabeto[i] = alfabeto[i] / 2;
        } else {
            if (impar == -1) {
                impar = i;
            } else {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
    }

    if (impar != -1) {
        for (int i = 0; i < alfabeto[impar]; i++) {
            str += char(impar + 65);
        }
    }

    for (int i = 25; i >= 0; i--) {
        if (i != impar) {
            for (int j = 0; j < alfabeto[i]; j++) {
                str += char(i + 65);
            }
        }
    }

    cout << str << "\n";
}