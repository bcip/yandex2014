#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;
const int MOD = 1000000007; 

int mpow(int a, int b){
    if (!b) return 1;
    if (b & 1) return (mpow(a, b - 1) * 1LL * a) % MOD;
    int temp = mpow(a, b / 2);
    return (temp * 1LL * temp) % MOD;
}

struct Fun {
    int d0, d1, d2;
    Fun (ll _d0, ll _d1, ll _d2):d0(_d0 % MOD), d1(_d1 % MOD), d2(_d2 % MOD){}
    Fun operator()(const Fun& a) {
        assert(a.d0 == 1);
        return Fun (
            d0,
            d1 * 1LL * a.d1,
            (d2 * 1LL * a.d1) % MOD * a.d1 +  d1 * 1LL * a.d2
        );
    }
};

Fun operator+(const Fun& a, const Fun& b) {
    return Fun(a.d0 + b.d0, a.d1 + b.d1, a.d2 + b.d2);              
}

Fun operator*(const Fun& a, const Fun& b) {
    return Fun(
        a.d0 * ll(b.d0),
        a.d1 * ll(b.d0) + a.d0 * ll(b.d1),
        a.d2 * ll(b.d0) + 2LL * a.d1 * ll(b.d1) + a.d0 * ll(b.d2)
    );
}

int main(){
    int n;
    scanf("%d", &n);
    Fun f(1, 1, 0);
    Fun x(1, 1, 0);
    for (int it = 0; it < n; it++) {
       	int k;
       	scanf("%d", &k);
        vector<int> g(k+1); 
       	int sum = 0;
       	for (int i = 0; i <= k; i++)
       		scanf("%d",&g[i]), sum += g[i];
        sum = mpow(sum, MOD - 2);
        for (int i = 0; i <= k; i++)
        	g[i] = (g[i] * 1LL * sum) % MOD;
        Fun p(0, 0, 0);
        for (int i = g.size()-1; i >= 0; i--)
            p = p * x + Fun(g[i], 0, 0);       
        f = f(p);
    }
    int res = f.d2;
    res = (res * 1LL * (MOD + 1) / 2) % MOD;
    printf("%d\n", res);
    return 0;
}