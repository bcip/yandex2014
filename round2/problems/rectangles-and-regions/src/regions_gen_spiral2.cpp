#include "testlib.h"
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
int a, b, c, d, n, m, k, p;
int mas[2002][2002];


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
int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &m);
	sscanf(argv[3], "%d", &k);
	//n = m = 2000; k = 500000;
	printf("%d %d\n", n, m);
	memset(mas, -1, sizeof(mas));
	d = 0;
	int ci = 0, cj = 0;
	while (1) {
		mas[ci][cj] = 1;
		int ni = ci + di[d];
		int nj = cj + dj[d];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || mas[ni][nj] != -1) {
			d = (d + 1) % 4;
		}
		int nni = ci + di[d] * 2;
		int nnj = cj + dj[d] * 2;
		if (mas[nni][nnj] != -1) {
			d = (d + 1) % 4;
		}
		ci += di[d];
		cj += dj[d];
		if (mas[ci][cj] != -1) break;
	}
	rept(i, n) {
		rept(j, m) {
			if (mas[i][j] == -1) mas[i][j] = 0;
		}
	}

	rept(i, n) {
		rept(j, m) {
			printf("%d", mas[i][j]);
		}
		printf("\n");
	}

	rept(i, n) {
		rept(j, m) {
			mas[i][j] += '0';
		}
	}

	rept(i, n) {
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
				if (!i) cs2[z][i][j] += cs2[z][i][j - 1]; else
				if (!j) cs2[z][i][j] += cs2[z][i - 1][j]; else
					cs2[z][i][j] += cs2[z][i - 1][j] + cs2[z][i][j - 1] - cs2[z][i - 1][j - 1];
			}
		}
	}

	printf("%d\n", k);
	c = 0;
	rept(i, k) {
		while (1) {
			int x1 = rnd.next(1, n);
			int y1 = rnd.next(1, m);
			int x2 = rnd.next(1, n);
			int y2 = rnd.next(1, m);
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);

			if (rnd.next(0, 1)) x2 = x1 + 1; else
				y2 = y1 + 1;

			if (i < 1001) {
				x1 = n / 2 - i + rnd.next(-1, 1);
				y1 = m / 2 - i + rnd.next(-1, 1);
				x2 = n / 2 + i + rnd.next(-1, 1);
				y2 = m / 2 + i + rnd.next(-1, 1);
			}
			if (x1 < 1) x1 = 1;
			if (y1 < 1) y1 = 1;
			if (x2 > m - 1) x2 = m;
			if(y2 > m) y2 = m;

			int t = solve(x1 - 1, y1 - 1, x2 - 1, y2 - 1);
			if (t != 2 && rnd.next(1, 1000000)) continue;
			if (i > 1001 && rnd.next(1000) == 0) {
				x1 = rnd.next(1, n);
				y1 = rnd.next(1, m);
				x2 = rnd.next(1, n);
				y2 = rnd.next(1, m);
			}
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			printf("%d %d %d %d\n", x1, y1, x2, y2);
			break;
		}
	}
}
