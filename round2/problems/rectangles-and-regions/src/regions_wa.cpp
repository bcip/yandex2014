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
#pragma comment(linker, "/STACK:266777216")
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

const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };

int a, b, c, d, n, m, k;
char mas[2002][2002];
int cs[2002][2002], cs2[4][2002][2002];
int hor[2002][2002], ver[2002][2002];
bool used[2002][2002];

pii sof[4];
pii q[4000002];
void bfs(int bi, int bj) {
	int a = 0, b = 0;
	q[b++] = mp(bi, bj);
	used[bi][bj] = 1;
	while (a < b) {
		int ci = q[a].x;
		int cj = q[a++].y;
		sof[0] = min(sof[0], pii(ci, cj));
		sof[1] = min(sof[1], pii(cj, ci));
		sof[2] = min(sof[2], pii(-ci, -cj));
		sof[3] = min(sof[3], pii(-cj, -ci));
		rept(i, 4) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
			if (used[ni][nj] || mas[ni][nj] != mas[ci][cj]) continue;
			used[ni][nj] = 1;
			q[b++] = mp(ni, nj);
		}
	}
}
inline int sum(int x, int y) {
	if (x < 0 || y < 0) return 0;
	return cs[x][y];
}
inline int sum(int x1, int y1, int x2, int y2) {
	return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}
inline int sum2(int t, int x, int y) {
	if (x < 0 || y < 0) return 0;
	return cs2[t][x][y];
}
inline int sum2(int t, int x1, int y1, int x2, int y2) {
	return sum2(t, x2, y2) - sum2(t, x1 - 1, y2) - sum2(t, x2, y1 - 1) + sum2(t, x1 - 1, y1 - 1);
}
inline int solve(int r1, int c1, int r2, int c2) {
	int t = sum(r1, c1, r2, c2);
	if (!t || t == (r2 - r1 + 1) * (c2 - c1 + 1)) return 1;

	if (r1 == r2) {
		if (hor[r1][c2] - hor[r1][c1] == 1) return 2; else
			return 0;
	}
	if (c1 == c2) {
		if (ver[r2][c1] - ver[r1][c1] == 1) return 2; else
			return 0;
	}

	int cnt = hor[r1][c2] - hor[r1][c1] + 1;
	cnt += hor[r2][c2] - hor[r2][c1];
	cnt += ver[r2][c1] - ver[r1][c1];
	cnt += ver[r2][c2] - ver[r1][c2] - 1;

	if (cnt > 2) return 0;

	if (cnt <= 1) {
		if (sum2(0, r1 + 1, c1 + 1, r2 - 1, c2 - 1) <= 1) return 2; else
			return 0;
	}

	rept(i, 4) {
		if (!sum2(i, r1 + 1, c1 + 1, r2 - 1, c2 - 1)) return 2;
	}
	return 0;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(mas[0]);
	sscanf(mas[0], "%d%d", &n, &m);
	rept(i, n) {
		gets(mas[i]);
		rept(j, m) {
			cs[i][j] = mas[i][j] - '0';
			if (!i && !j); else
			if (!j) cs[i][j] += cs[i - 1][j]; else
			if (!i) cs[i][j] += cs[i][j - 1]; else
				cs[i][j] += cs[i - 1][j] + cs[i][j - 1] - cs[i - 1][j - 1];
		}
	}

	rept(i, n) {
		rept(j, m) {
			hor[i][j] = 0;
			if (j && mas[i][j] != mas[i][j - 1]) ++hor[i][j];
			if (j) hor[i][j] += hor[i][j - 1];

			ver[i][j] = 0;
			if (i && mas[i - 1][j] != mas[i][j]) ++ver[i][j];
			if (i) ver[i][j] += ver[i - 1][j];
		}
	}

	C(used);
	rept(i, n) {
		rept(j, m) {
			if (!used[i][j]) {
				sof[0] = sof[1] = sof[2] = sof[3] = mp(INF, INF);
				bfs(i, j);
				cs2[0][sof[0].x][sof[0].y] = 1;
				cs2[1][sof[1].y][sof[1].x] = 1;
				cs2[2][-sof[2].x][-sof[2].y] = 1;
				cs2[3][-sof[3].y][-sof[3].x] = 1;
			}
		}
	}

	rept(z, 4) {
		rept(i, n) {
			rept(j, m) {
				if (!i && !j) continue;
				if (!i)  cs2[z][i][j] += cs2[z][i][j - 1]; else
				if (!j) cs2[z][i][j] += cs2[z][i - 1][j]; else
					cs2[z][i][j] += cs2[z][i - 1][j] + cs2[z][i][j - 1] - cs2[z][i - 1][j - 1];
			}
		}
	}

	scanf("%d", &k);
	int sq = 0;
	rept(i, k) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2); --r1; --c1; --r2; --c2;
		int t = solve(r1, c1, r2, c2);
		printf("%d\n", t);

		if (t == 2) {
			sq = max(sq, (r2 - r1 + 1) * (c2 - c1 + 1));
		}
	}

	if (n > 10 || m > 10) return sq;
}