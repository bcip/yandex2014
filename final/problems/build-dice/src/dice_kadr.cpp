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

struct cube {
	VI a;
	cube() {
		a.resize(6);
	}
	inline void go_right() {
		VI b(6);
		b[0] = a[0];
		b[1] = a[1];
		b[2] = a[5];
		b[3] = a[4];
		b[4] = a[2];
		b[5] = a[3];
		a.swap(b);
	}
	inline void go_left() {
		rept(i, 3) go_right();
	}
	inline void go_up() {
		VI b(6);
		b[0] = a[5];
		b[1] = a[4];
		b[2] = a[2];
		b[3] = a[3];
		b[4] = a[0];
		b[5] = a[1];
		a.swap(b);
	}
	inline void go_down() {
		rept(i, 3) go_up();
	}
	inline void whoaa() {
		VI b(6);
		b[0] = a[2];
		b[1] = a[3];
		b[2] = a[1];
		b[3] = a[0];
		b[4] = a[4];
		b[5] = a[5];
		a.swap(b);
	}
	inline int get_hash() {
		int h = 1;
		rept(i, 6) {
			h = h * 6 + a[i];
		}
		return h;
	}
};

int a, b, c, d, n, m, k;
bool sm[6][6];
char mas[7][7];
const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };
cube get_next(cube cur, int dir) {
	if (dir == 0) cur.go_right(); else
	if (dir == 1) cur.go_down(); else
	if (dir == 2) cur.go_left(); else
	cur.go_up();
	return cur;
}
set<int> was;
bool dfs(cube cur, int mask, int ci, int cj) {
	if (mask == 63) return 1;
	int h = (cur.get_hash() << 6) | mask;
	h = h * 6 + ci;
	h = h * 6 + cj;
	if (was.count(h)) return 0;
	was.insert(h);
	rept(i, 4) {
		int ni = ci + di[i];
		int nj = cj + dj[i];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || mas[ni][nj] == '0') continue;
		cube nx = get_next(cur, i);
		if (nx.a[5] != mas[ni][nj] - '0') continue;
		if (dfs(nx, mask | 1 << (nx.a[5] - 1), ni, nj)) return 1;
	}
	return 0;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cube beg;
	rept(i, 6) {
		scanf("%d", &beg.a[i]);// --beg.a[i];
	}

	while (scanf("%s", mas[n]) > 0) {
		++n;
	}
	m = (int)strlen(mas[0]);

	int bi = -1, bj = -1;
	rept(i, n) {
		rept(j, m) {
			if (mas[i][j] - '0' == beg.a[5]) {
				bi = i;
				bj = j;
			}
		}
	}
	rept(z, 8) {
		was.clear();
		if (dfs(beg, 1 << (beg.a[5] - 1), bi, bj)) {
			printf("Yes\n");
			exit(0);
		}
		beg.whoaa();
		if (z == 3) {
			reverse(mas, mas + n);
			bi = n - bi - 1;
		}
	}
	printf("No\n");
}
