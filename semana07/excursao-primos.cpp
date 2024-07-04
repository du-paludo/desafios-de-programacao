#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> sieve (1e7+15, true);

void eratosthene(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (ll j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll t, n, k;
    cin >> t;

    eratosthene(1e7);

    set<ll> primes;

    for (ll i = 0; i < t; i++) {
        cin >> n >> k;
        ll currentProduct = 1;
        ll count = 0;
        for (ll j = 2; j < n; j++) {
            if (sieve[j]) {
                if (count == k) {
                    if (currentProduct / *primes.begin() * j <= n) {
                        currentProduct /= *primes.begin();
                        count--;
                        primes.erase(primes.begin());
                    } else {
                        break;
                    }
                }
                currentProduct *= j;
                count++;
                primes.insert(j);
            }
        }
        primes.clear();
        cout << currentProduct << '\n';
    }
}