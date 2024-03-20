#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll a, b, prime;
    int n;
    cin >> a, b, n;
    set<ll> primes;
    for (int i = 0; i < n; i++) {
        cin >> prime;
        primes.insert(prime);
    }
}