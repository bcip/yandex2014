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

int a, b, c, d, n, m, k, p;
int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &m);
	sscanf(argv[3], "%d", &p);
	printf("%d %d\n", n, m);
	rept(i, n) {
		rept(j, m) {
			if (rnd.next(0, 100) < p) printf("0"); else
			printf("1");
		}
		printf("\n");
	}

	vector<VI> q;
	rept(i1, n) {
		rept(j1, m) {
			FOR(i2, i1, n - 1) {
				FOR(j2, j1, m - 1) {
					VI t(4);
					t[0] = i1; t[1] = j1; t[2] = i2; t[3] = j2;
					q.pb(t);
				}
			}
		}
	}
	
	printf("%d\n", L(q));
	shuffle(all(q));
	if (L(q) > 500000) q.resize(500000);
	rept(i, L(q)) {
		printf("%d %d %d %d\n", q[i][0] + 1, q[i][1] + 1, q[i][2] + 1, q[i][3] + 1);
	}
}
