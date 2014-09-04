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

const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };
int a, b, c, d, n, m, k, p;
int mas[2002][2002];
int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &m);
	sscanf(argv[3], "%d", &k);
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

	printf("%d\n", k);
	rept(i, k) {
		int x1 = rnd.next(1, n);
		int y1 = rnd.next(1, m);
		int x2 = rnd.next(1, n);
		int y2 = rnd.next(1, m);
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		printf("%d %d %d %d\n", x1, y1, x2, y2);
	}
}
