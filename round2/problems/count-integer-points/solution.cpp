#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

inline pii operator + (const pii &a, const pii &b) {
	return mp(a.x + b.x, a.y + b.y);
}

inline pii operator * (const pii &a, int x) {
	return mp(a.x * x, a.y * x);
}

inline bool operator == (const pii &a, const pii &b) {
	return (a.x == b.x) && (a.y == b.y);
}

int main()
{
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
    int n;
    pii a, b, c;
    cin >> n;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    int shift = INF;
    int ri , rj;
    for (int i = - n + 1; i < n; i++)
        for (int j = - n + 1; j < n; j++) {
            if (i == 0 && j == 0) continue;
            pii t = a * i + b * j;
            int k = t.x / c.x;
            if (t == c * k) {
                if (k > 0 && k < shift) {
                    shift = k;
                    ri = abs(i);
                    rj = abs(j);
                }
            }
        }
    if (shift >= n) {
        cout << (ll)n * (ll)n * n << endl;
        exit(0);
    }
    int ans = (ll)n * (ll)n * shift + (ll)(n - shift) * (ll)(n * n - ((n - ri) * (n - rj)));
    cout << ans << endl;
	return 0;
}
