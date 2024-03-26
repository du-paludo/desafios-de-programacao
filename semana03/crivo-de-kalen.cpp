#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll a, b, prime, n;
    cin >> a >> b >> n;

    ll count = b - a + 1;
    ll primes[n];

    for (int i = 0; i < n; i++) {
        cin >> prime;
        primes[i] = prime;
    }

    // The number of subsets of n
    ll powerSetSize = 1 << n;
    // The sum of odd number of prime numbers
    ll odd = 0;
    // The sum of even number of prime numbers
    ll even = 0;

    // If n = 2, iterates from 01 to 11
    for (ll i = 1; i < powerSetSize; i++) {
        ll p = 1;
        for (ll j = 0; j < n; j++) {
            // If the bit corresponding to j is turned on, multiply primes[j]
            if (i & (1 << j)) {
                p *= primes[j];
            }
        }
        // If the number of bits turned on is odd, sum in odd
        if (__builtin_popcountll(i) & 1) {
            odd += b/p - (a-1)/p;
        // else, sum in even
        } else {
            even += b/p - (a-1)/p;
        }
    }

    // The number of elements remaining is the difference between (b-a) and (odd sum - even sum)
    cout << count - (odd - even) << "\n";
}