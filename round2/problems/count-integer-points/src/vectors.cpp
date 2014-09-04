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

inline pii operator +(const pii &a, const pii &b) {
	return mp(a.x + b.x, a.y + b.y);
}
inline pii operator -(const pii &a, const pii &b) {
	return mp(a.x - b.x, a.y - b.y);
}
inline pii operator *(const pii &a, const int &b) {
	return mp(a.x * b, a.y * b);
}
int a, b, c, d, n, m, k;
pii v[3];
pair<pii, pii> p[4000002];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	rept(i, 3) {
		scanf("%d%d", &v[i].x, &v[i].y);
	}
	
	rept(i, 3) {
		if (v[i].x && v[i].y) {
			swap(v[i], v[2]);
			break;
		}
	}

	rept(i, n) {
		rept(j, n) {
			pii t = v[0] * i + v[1] * j;
			int need = min(t.x / v[2].x, t.y / v[2].y);
			pii tt = t - v[2] * need;
			p[k++] = mp(tt, mp(t.x % v[2].x, t.x));
		}
	}

	sort(p, p + k);
	ll ans = 0;
	rept(i, k) {
		if (i && p[i - 1].x == p[i].x && p[i - 1].y.x == p[i].y.x) continue;
		FOR(j, i, k - 1) {
			if (p[j].x != p[i].x || p[j].y.x != p[i].y.x) break;
			int x = p[j].y.y;
			int nx = INF;
			if (j + 1 < k && p[j + 1].x == p[j].x && p[j + 1].y.x == p[j].y.x) nx = p[j + 1].y.y;
			int diff = (nx - x) / v[2].x;
			ans += min(diff, n);
		}
	}
	cout << ans << endl;
}
