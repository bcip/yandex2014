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

int a, b, c, d, n, m, k, l, r;
int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &l);
	sscanf(argv[3], "%d", &r);
	printf("%d\n", n);
	rept(i, n) {
		if (i) printf(" ");
		printf("%d", rnd.next(l, r));
	}
	printf("\n");
}
