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


const char *a1[] = { "10000000000000000000", "10111111111111111110", "11100000000000000010", "00001111111111111010", "01111000000000001010", "01000011111111101010", "01011110000000101010", "01010000111110101010", "01010111100010101010", "01010100001010101010", "01010101111010101010", "01010101000010101010", "01010101111110101010", "01010100000000101010", "01010111111111101010", "01010000000000001010", "01011111111111111010", "01000000000000000010", "01111111111111111110", "00000000000000000000" };
const char *a2[] = { "10000000000000000000", "10111111111111111110", "10100000000000000010", "10101111111111111110", "10101000000000000000", "10101011111111111111", "10101010000000000001", "10101010111111111101", "10101010100000000101", "10101010101111110101", "10101010100000010101", "10101010111111010101", "10101010000001010101", "10101011111111010101", "10101000000000010101", "10101111111111110101", "10100000000000000101", "10111111111111111101", "10000000000000000001", "11111111111111111111" };
int a, b, c, d, n, m, k, p, t;
char str[2003];
int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);

	sscanf(argv[1], "%d", &k);
	sscanf(argv[2], "%d", &t);
	
	if (t == 0) {
		n = 20; m = 40;
		printf("%d %d\n", n, m);
		rept(i, n) {
			printf("%s%s\n", a1[i], a2[i]);
		}
	} else
	if (t == 1) {
		n = 40; m = 20;
		printf("%d %d\n", n, m);
		rept(i, 20) {
			printf("%s\n", a1[i]);
		}
		rept(i, 20) {
			printf("%s\n", a2[i]);
		}
	}
	else {
		n = m = 2000;
		printf("2000 2000\n");
		rept(i, 20) {
			rept(m1, 100) {
				rept(j, 20) {
					rept(m2, 100) {
						printf("%c", a1[i][j]);
					}
				}
				printf("\n");
			}
		}
	}

	if ((ll)n * (n + 1) / 2 * m * (m + 1) / 2 <= 500000) {
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

		shuffle(all(q));
		if (L(q) > k) q.resize(k);
		printf("%d\n", L(q));
		rept(i, L(q)) {
			printf("%d %d %d %d\n", q[i][0] + 1, q[i][1] + 1, q[i][2] + 1, q[i][3] + 1);
		}
	}
	else {
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
}
