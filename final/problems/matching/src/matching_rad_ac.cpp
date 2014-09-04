#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

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
#include <complex>
#include <iomanip>

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

const int MOD = 1000000007;

int n1, n2, pw3[21], z[110][60000], g[110];

inline int get_bit(int msk, int k) {
  return msk / pw3[k] % 3;
}

inline int set_bit(int msk, int k, int val) {
  return msk + pw3[k] * (val - get_bit(msk, k));
}

int rec(int v, int msk) {
  if (z[v][msk] != -1)
    return z[v][msk];

  int res = 0;
  if (v == n2) {
    res = 1;
    forn(i, n1)
      if (get_bit(msk, i) == 1) {
        res = 0;
        break;
      }
    return z[v][msk] = res;
  }
  
  int nmsk = msk;
  forn(i, n1)
    if (get_bit(g[v], i) == 1) {
      int bt = get_bit(msk, i);
      if (bt != 2) {
        res += rec(v + 1, msk + pw3[i] * (2 - bt));
        if (res >= MOD)
          res -= MOD;
      }
      if (bt == 0)
        nmsk += pw3[i];
    }
  res += rec(v + 1, nmsk);
  if (res >= MOD)
    res -= MOD;

  return z[v][msk] = res;
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  pw3[0] = 1;
  forn(i, 20)
    pw3[i + 1] = pw3[i] * 3;
  
  int m;
  cin >> n1 >> n2 >> m;
  forn(i, m) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    g[v2] = set_bit(g[v2], v1, 1);
  }

  memset(z, -1, sizeof(z));
  int res = rec(0, 0);
  cout << res << endl;
  
  return 0;
}