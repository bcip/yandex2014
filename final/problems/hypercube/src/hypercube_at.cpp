#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

void solve() {
    int k; cin >> k;
    vector<int> a(k); for (int i = 0; i < k; ++i) cin >> a[i];
    set<int> s(a.begin(), a.end());
    vector<int> m(1<<20); for (int i = 0; i < k; ++i) m[a[i]]++;
    for (int d = 1; d < 30 && s.size() < 30; ++d) {
        int cnt = 0;
        int has = 1 << (d - 1);
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it) cnt += (has - 1 + m[*it]) / has;
        if (cnt <= d) {
            cout << d << endl;
            return;
        }
    }
    
    cout << s.size() << endl;
}

int main() {
    cin.sync_with_stdio(false);
    solve();
    return 0;
}
