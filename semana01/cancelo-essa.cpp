#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string input;
    string parsedInput;
    vector<string> inputArray;
    stringstream ss;
    int h, m;

    while (getline(cin, input)) {
        stringstream ss(input);
        while (getline(ss, parsedInput, ' ')) {
            inputArray.push_back(parsedInput);
        }
        if (stoi(inputArray[1]) > 10) {
            cout << "Abel deve cancelar " << inputArray[0] << "\n";
        } else if (stoi(inputArray[1]) == 10 && stoi(inputArray[2]) > 0) {
            cout << "Abel deve cancelar " << inputArray[0] << "\n";
        } else {
            cout << "Abel deve cursar " << inputArray[0] << "\n";
        }
        inputArray.clear();
    }
}