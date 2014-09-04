#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a, b, c, d, n, m, k;
int fen[50002];
inline void upd(int x, int val) {
	for (; x < n; x |= x + 1) fen[x] += val;
}
inline int fnd(int x) {
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1) ans += fen[x];
	return ans;
}
inline int get_k(int k) {
	int l = -1, r = n - 1;
	while (r - l > 1) {
		int xx = (r + l) / 2;
		if (fnd(xx) <= k) l = xx; else
			r = xx;
	}
	return r;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &k);
	if (!k) {
		printf("1\n1\n");
		exit(0);
	}

	rep(i, INF) {
		if (i * (i - 1) / 2 >= k) {
			n = i;
			break;
		}
	}
	printf("%d\n", n);
	VI res(n, -1);
	rept(i, n) {
		upd(i, 1);
	}

	rept(i, n) {
		int need = k - (n - i - 1) * (n - i - 2) / 2;
		if (need < 0) need = 0;
		res[i] = get_k(need);
		k -= need;
		upd(res[i], -1);
	}
	rept(i, L(res)) {
		if (i) printf(" ");
		printf("%d", res[i] + 1);
	}
	printf("\n");
}
