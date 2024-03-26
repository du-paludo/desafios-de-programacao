#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bitset<30> smallestValue("111111111111111111111111111111");

void sequenceDivision(vector<bitset<30>>& sequence, vector<int>& divisions, int k, int n) {
    if (k == n-1) {
        vector<bitset<30>> values;
        bitset<30> temp(0);
        for (int i = 0; i < n-1; i++) {
            temp = temp | sequence[i];
            if (divisions[i] == 1) {
                values.push_back(temp);
                temp = 0;
            }
        }

        if (divisions[n-2] == 1) {
            values.push_back(sequence[n-1]);
        } else {
            values.push_back(temp | sequence[n-1]);
        }

        bitset<30> xorResult;
        if (values.size() == 1) {
            xorResult = values[0];
        } else if (values.size() >= 2) {
            xorResult = values[0] ^ values[1];
            for (int i = 2; i < values.size(); i++) {
                xorResult = xorResult ^ values[i];
            }
        }
        if (xorResult.to_ullong() < smallestValue.to_ullong()) {
            smallestValue = xorResult;
        }
    } else {
        divisions[k] = 0;
        sequenceDivision(sequence, divisions, k+1, n);
        divisions[k] = 1;
        sequenceDivision(sequence, divisions, k+1, n);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    ll value;
    vector<bitset<30>> sequence;
    for (int i = 0; i < n; i++) {
        cin >> value;
        sequence.push_back(value);
    }
    
    if (n == 1) {
        cout << sequence[0].to_ullong() << "\n";
    } else {
        vector<int> divisions(n-1);
        sequenceDivision(sequence, divisions, 0, n);
        cout << smallestValue.to_ullong() << "\n";
    }
}