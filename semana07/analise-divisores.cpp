#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007
#define MOD_EXP (MOD-1)

// Function to perform modular exponentiation
ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    
    vector<pair<long long, long long>> factors(n);
    
    for (int i = 0; i < n; i++) {
        cin >> factors[i].first >> factors[i].second;
    }
    
    ll num_divisors = 1;
    ll sum_divisors = 1;
    ll product_divisors = 1;
    ll exp_product = 1;
    
    for (auto factor : factors) {
        ll p = factor.first;
        ll k = factor.second;
        
        // Number of divisors
        num_divisors = num_divisors * (k + 1) % MOD;
        
        // Sum of divisors
        ll p_power_k_plus_1 = mod_exp(p, k + 1, MOD);
        ll sum_term = (p_power_k_plus_1 - 1 + MOD) % MOD * mod_exp(p - 1, MOD - 2, MOD) % MOD;
        sum_divisors = sum_divisors * sum_term % MOD;
        
        // Exponentiation for product calculation
        exp_product = exp_product * (k + 1) % MOD_EXP;
    }
    
    // Product of divisors
    ll n_product = 1;
    for (auto factor : factors) {
        ll p = factor.first;
        ll k = factor.second;
        
        ll exponent = (k * exp_product / 2) % MOD_EXP;
        product_divisors = product_divisors * mod_exp(p, exponent, MOD) % MOD;
    }
    
    cout << num_divisors << " " << sum_divisors << " " << product_divisors << endl;
    
    return 0;
}