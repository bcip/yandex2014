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

const int NMAX = 7010;

int um[NMAX], us, dp[NMAX];

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int n;
  cin >> n;

  set<int> cand;
  for (int i = 1; i <= n; i++)
    cand.insert(n / i + 1);
  cand.insert(1);

  string ans(n, 'F');
  for (set<int>::iterator it = cand.begin(); it != cand.end(); it++) {
    int l = *it;
    if (l + l > n)
      break;

    forn(i, l)
      dp[i] = 0;

    for (int i = l; i <= n; i++) {
      us++;
      for (int j = 0; j <= i - j - l; j++) {
        int v = dp[j] ^ dp[i - j - l];
        um[v] = us;
      }

      forn(j, INF)
        if (um[j] != us) {
          dp[i] = j;
          break;
        }
    }

    if (dp[n] == 0)
      ans[l - 1] = 'S';
  }
  
  cout << ans << endl;
  
  return 0;
}
