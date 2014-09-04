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

int n, d, a[310000], adj[310000];

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  cin >> n >> d;
  forn(i, n)
    scanf("%d", &a[i]);

  map<int, int> w;
  forn(i, n) {
    adj[i] = -INF;
    if (w.count(a[i] - d))
      adj[i] = w[a[i] - d];
    if (w.count(a[i] + d))
      adj[i] = max(adj[i], w[a[i] + d]);

    w[a[i]] = i;
  }

  int64 ans = 0;
  forn(l, n) {
    int nl = INF;
    for (int r = l; r < n; r++)
      if (l <= adj[r]) {
        ans += int64(n - r) * (adj[r] - l + 1);
        nl = adj[r];
        break;
      }
    l = nl;
  }

  cout << ans << endl;
  
  return 0;
}