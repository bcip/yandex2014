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

int main(int argc, char *argv[])
{
	setName("compares if the output corresponds to input");
	registerTestlibCmd(argc, argv);

	int k = inf.readInt();
	
	int need = ans.readInt();

	int n = ouf.readInt();
	if (n != need) {
		quitf(_wa, "Expected n = %d, found n = %d", need, n);
	}
	VI p(n);
	rept(i, n) {
		p[i] = ouf.readInt(1, n);
		--p[i];
	}
	VI sr = p;
	SORT(sr);
	sr.resize(unique(all(sr)) - sr.begin());
	if (L(sr) != L(p)) {
		quitf(_wa, "Duplicate elements");
	}

	VI fen(n + 1);
	int ans = 0;
	FORD(i, L(p) - 1, 0) {
		for (int x = p[i]; x >= 0; x = (x & (x + 1)) - 1) ans += fen[x];
		for (int x = p[i]; x < n; x |= x + 1) ++fen[x];
	}
	if (ans != k) {
		quitf(_wa, "Expected %d inversions, got %d", k, ans);
	}

	quitf(_ok, "OK");
}