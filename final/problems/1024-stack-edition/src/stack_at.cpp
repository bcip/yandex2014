#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void relax(vector<double>& y, vector<double> x, double t1, double t2) {
    y[0] = min(y[0], *min_element(x.begin(), x.end()) + 2 + t1);
    y[1] = min(y[1], y[0] + t1);
    y[1] = min(y[1], *min_element(x.begin(), x.end()) + 2 + t2);
    for (int i = 2; i <= 11; ++i) {
        y[i] = min(y[i], *min_element(x.begin(), x.end()) + 2 + t2 * (1 << (i - 1)));
        y[i] = min(y[i], y[i-1] + t2 * (1 << (i - 2)));
    }
}

void solve() {
    int n, P;
    cin >> n >> P;
    vector<int> s(n);
    
    int deleted = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int k = 0; k <= 10; ++k) if (s[i] == (1 << k)) s[i] = k;
    }
    
    double q = (100 - P) / 100.0;
    double p = P / 100.0;
    
    double t1 = p * q / (1 - q) / (1 - q);
    double t2 = min(q * p / (1 - p + 1e-100) / (1 - p + 1e-100), t1 * p);
    
    vector<double> x(12, 1e10);
    x[s.back()] = 0;
    s.pop_back();
    relax(x, vector<double>(12, 1e10), t1, t2);
    
    while (s.size()) {
        vector<double> y(12, 1e10);
        y[s.back()] = *min_element(x.begin(), x.end()) + 1;
        y[s.back() + 1] = x[s.back()];
        s.pop_back();
        
        relax(y, x, t1, t2);
        x = y;
    }
    
    printf("%.10lf", x[10]);
}

int main() {
    solve();
    return 0;
}