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
char mas[2002][2002];
bool used[2002][2002];
pii cu[4000002];

const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };

int r1, c1, r2, c2;
void dfs(int ci, int cj) {
	used[ci][cj] = 1;
	cu[c++] = mp(ci, cj);
	rept(i, 4) {
		int ni = ci + di[i];
		int nj = cj + dj[i];
		if (ni < r1 || ni > r2 || nj < c1 || nj > c2) continue;
		if (used[ni][nj] || mas[ni][nj] != mas[ci][cj]) continue;
		dfs(ni, nj);
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(mas[0]);
	sscanf(mas[0], "%d%d", &n, &m);
	rept(i, n) {
		gets(mas[i]);
	}

	scanf("%d", &k);
	rept(hod, k) {
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2); --r1; --c1; --r2; --c2;
		c = 0;
		int cur = 0;
		FOR(i, r1, r2) {
			FOR(j, c1, c2) {
				if (used[i][j]) continue;
				dfs(i, j);
				++cur;
				if (cur == 3) break;
			}
			if (cur == 3) break;
		}
		rept(i, c) {
			used[cu[i].x][cu[i].y] = 0;
		}
		if (cur == 3) cur = 0;
		printf("%d\n", cur);
	}
}
