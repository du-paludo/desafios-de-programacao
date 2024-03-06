// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    int expr = a+b+c;

    if (a+b-c < expr) {
        expr = a+b-c;
    }
    if (a+b*c < expr) {
        expr = a+b*c;
    }
    if (a-b+c < expr) {
        expr = a-b+c;
    }
    if (a-b-c < expr) {
        expr = a-b-c;
    }
    if (a-b*c < expr) {
        expr = a-b*c;
    }
    if (a*b+c < expr) {
        expr = a*b+c;
    }
    if (a*b-c < expr) {
        expr = a*b-c;
    }
    if (a*b*c < expr) {
        expr = a*b*c;
    }

    cout << expr << '\n';
}