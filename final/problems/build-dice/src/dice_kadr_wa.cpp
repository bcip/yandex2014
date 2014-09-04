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
int cube[6];
bool sm[6][6];
char mas[7][7];
inline void add(VI a) {
	a.pb(a[0]);
	rept(i, L(a) - 1) {
		sm[cube[a[i]]][cube[a[i + 1]]] = sm[cube[a[i + 1]]][cube[a[i]]] = 1;
	}
}
const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	rept(i, 6) {
		scanf("%d", &cube[i]); --cube[i];
	}

	VI t(4);
	t[0] = 0; t[1] = 4; t[2] = 1; t[3] = 5;
	add(t);
	t[0] = 0; t[1] = 2; t[2] = 1; t[3] = 3;
	add(t);
	t[0] = 2; t[1] = 4; t[2] = 3; t[3] = 5;
	add(t);

	while (scanf("%s", mas[n]) > 0) {
		++n;
	}

	m = (int)strlen(mas[0]);
	rept(i, n) {
		rept(j, m) {
			if (mas[i][j] == '0') continue;
			rept(z, 4) {
				int ni = i + di[z];
				int nj = j + dj[z];
				if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
				if (mas[ni][nj] == '0') continue;
				if (!sm[mas[i][j] - '1'][mas[ni][nj] - '1']) {
					printf("No\n");
					exit(0);
				}
			}
		}
	}
	printf("Yes\n");
}
