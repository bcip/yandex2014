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

int z[110000][20], n;

int rec(int msk, int l) {
  if (z[msk][l] != -1)
    return z[msk][l];

  int seg_l = (1 << l) - 1;
  forn(i, n - l + 1) {
    if (msk & (seg_l << i))
      continue;
    if (!rec(msk | (seg_l << i), l))
      return z[msk][l] = 1;
  }
  
  return z[msk][l] = 0;
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  cin >> n;

  memset(z, -1, sizeof(z));
  int ans1, ans2;
  ans1 = ans2 = -1;
  for (int l = 1; l <= n && !(ans1 != -1 && ans2 != -1); l++)
    if (rec(0, l)) {
      if (ans1 == -1)
        ans1 = l;
    } else {
      if (ans2 == -1)
        ans2 = l;
    }

  printf("%d %d\n", ans1, ans2);
  
  return 0;
}