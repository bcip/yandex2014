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

#define double long double

const int NMAX = 110;

double a[NMAX][NMAX], res[NMAX][NMAX], c[NMAX][NMAX];
int m;

void mult(double a[NMAX][NMAX], double b[NMAX][NMAX]) {
  forn(i, m)
    forn(j, m) {
      c[i][j] = 0;
      forn(k, m)
        c[i][j] += a[i][k] * b[k][j];
    }
  memcpy(a, c, sizeof(c));
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif	

  int64 n;
  int k;
  cin >> n >> k;

  a[0][0] = 0.5;
  a[1][0] = 0.5;
  for (int i = 1; i <= k; i++) {
    a[i + 1][i] = 0.5;
    a[1][i] = 0.5;
  }
  a[0][k + 1] = 0.5;
  a[1][k + 1] = 0.5;
  a[k + 2][k + 1] = 0.5;
  a[k + 2][k + 2] = 1;

  m = k + 3;
  forn(i, m)
    res[i][i] = 1;

  while (n > 0)
    if (n % 2 == 1) {
      mult(res, a);
      n--;
    } else {
      mult(a, a);
      n >>= 1;
    }

  double ans = res[k + 2][0];

  cout.precision(20);
  cout.setf(ios::fixed);
  cout << ans << endl;
	
  return 0;
}