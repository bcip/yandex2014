#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
typedef long long LL;

LL pow(LL x, LL p) {
    if (!p) return 1;
    LL y = pow(x, p / 2);
    y = y * y % MOD;
    if (p & 1) y = y * x % MOD;
    return y;
}

LL inv(LL x) {
    return pow(x, MOD - 2);
}

void solve() {
    int n;
    cin >> n;
    LL E(1), E2(1);
    
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; ++k;
        vector<int> a(k); for (int j = 0; j < k; ++j) cin >> a[j];
        int s(0); for (int j = 0; j < k; ++j) s += a[j];
        
        int ei(0); for (int j = 0; j < k; ++j) ei += a[j] * j; ei = ei * inv(s) % MOD;
        int ei2(0); for (int j = 0; j < k; ++j) ei2 += a[j] * j * j; ei2 = ei2 * inv(s) % MOD;
        
        E2 = (E2 - E) * ei % MOD * ei % MOD + E * ei2 % MOD;
        E2 = (E2 % MOD + MOD) % MOD;
        
        E = (E * ei ) % MOD;
    }
    
    cout << (E2 - E) * inv(2) % MOD << endl;
}

int main() {
    solve();
    return 0;
}