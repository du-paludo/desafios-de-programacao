#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const string& a, const string& b) {
    return a + b < b + a;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    multiset<string, bool (*)(const string&, const string&)> strSet (cmp);

    int n;
    cin >> n;

    string A;
    string result = "";

    for (int i = 0; i < n; i++) {
        cin >> A;
        strSet.insert(A);
    }

    for (auto it = strSet.begin(); it != strSet.end(); it++) {
        result += *it;
    }

    cout << result << '\n';
}