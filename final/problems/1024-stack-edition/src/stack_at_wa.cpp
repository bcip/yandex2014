#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void solve() {
    int n, P;
    cin >> n >> P;
    vector<int> s(n);
    
    int deleted = 0;
    
    for (int i = 0; i < n; ++i) cin >> s[i];
    
    if (s[0] == 1024) {
        cout << n - 1 << endl; return;
    }
    
    for (int i = 0; i + 1 < min(n, 11); ++i) {
        if (s[i] == s[i+1]) {
            s.resize(i + 2);
            deleted = n - (i + 2);
            break;
        }
        if (s[i] < s[i + 1]) {
            s.resize(i + 1);
            deleted = n - (i + 1);
            break;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) sum += s[i];
    
    if (P == 100) {
        cout << 1024 - sum + deleted << endl; return;
    }
    
    vector<double> f(1025);
    f[1024] = 0;
    double q = (100 - P) / 100.0;
    double p = P / 100.0;
    for (int i = 1023; i >= 0; --i) {
        if (i & 1) {
            // X = q + 2 * q^2 + ... = q / (1 - q) + q * X
            // X = q / (1 - q) ^ 2
            f[i] = min(f[i+1] + p * q / (1 - q) / (1 - q), 1 + f[i + 1] + q * p / (1 - p) / (1 - p));
        } else {
            f[i] = f[i+1] * p + f[i+2] * q;
            f[i] = min(f[i], min(f[i+1] + p * q / (1 - q) / (1 - q), f[i + 2] + q * p / (1 - p) / (1 - p)));
        }
    }
    
    printf("%.10lf", f[sum] + deleted);
}

int main() {
    solve();
    return 0;
}