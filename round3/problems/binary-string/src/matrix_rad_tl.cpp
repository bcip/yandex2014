#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

const int NMAX = 110;

int m;
double z[NMAX][NMAX];

double rec(int n, int p) {
  if (n == 0)
    return 0;

  if (z[n][p] > -0.5)
    return z[n][p];

  if (p == m - 2) {
    z[n][p] = rec(n - 1, 0) * 0.5 + rec(n - 1, 1) * 0.5 + 0.5;
  } else if (p == 0) {
    z[n][p] = rec(n - 1, 1) * 0.5 + rec(n - 1, 0) * 0.5;
  } else {
    z[n][p] = rec(n - 1, p + 1) * 0.5 + rec(n - 1, 1) * 0.5;
  }

  return z[n][p];
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif	

  int64 n;
  int k;
  cin >> n >> k;

  m = k + 3;

  if (n >= NMAX)
    for(;;);

  forn(i, NMAX)
    forn(j, NMAX)
      z[i][j] = -1;
  printf("%.10lf\n", rec((int)n, 0));
	
  return 0;
}