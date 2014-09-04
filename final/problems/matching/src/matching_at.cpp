#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

typedef pair<int, int> pii;

const int MOD = 1000000007;

int l, r, m;
int e[1000];

int id[1024][1024], ic;
pii pr[60000];

int memo[101][60000];

void add(int& a, int b) {
    a += b;
    if (a >= MOD) a-= MOD;
}

void solve() {
    cin >> l >> r >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y; --x; --y;
        e[y] ^= (1 << x);
    }
    
    for (int i = 0; i < 1024; ++i) {
        for (int j = 0; j < 1024; ++j)
            if ((i & j) == 0) {
                pr[ic] = pii(i, j);
                id[i][j] = ic++;
            }
    }
    
    memo[0][0] = 1;
    for (int j = 0; j < r; ++j) for (int st = 0; st < ic; ++st) {
        int nw = e[j] & (~pr[st].first) & (~pr[st].second);
        add(memo[j+1][id[pr[st].first][pr[st].second | nw]], memo[j][st]);
        for (int i = 0; i < l; ++i) 
            if ((e[j] & (1<<i)) > 0 && (pr[st].first & (1<<i)) == 0)
                add(memo[j+1][id[pr[st].first + (1<<i)][pr[st].second & (~(1<<i))]], memo[j][st]);
    }
    
    int res = 0;
    for (int ms = 0; ms < (1<<l); ++ms) add(res, memo[r][id[ms][0]]);
    
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}