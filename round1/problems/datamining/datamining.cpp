#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int k;
int n;
int t[10000];

const LL MD = (int) 1e9 + 7;

int main() {
    cin >> k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    if (k < n) {
        nth_element(t, t + k, t + n);
        cout << t[k] << endl;
        return 0;
    }
    k -= n - 1;
    LL a = 1;
    LL b = 0;
    for (int i = 0; i < k; ++i) {
        a += b;
        b = a - b;
        if (a > (int) 1e9) {
            break;
        }
    }
    pair<LL, LL> best(0LL, 0LL);
    for (int i = 0; i < n - 1; ++i) {
        LL x = max(t[i], t[i + 1]);
        LL y = min(t[i], t[i + 1]);
        if (a * x + b * y > a * best.first + b * best.second) {
            best = make_pair(x, y);
        }
    }
    LL x = best.first;
    LL y = best.second;
    for (int i = 0; i < k; ++i) {
        x += y;
        y = x - y;
        x %= MD;
    }
    cout << x << endl;
}
