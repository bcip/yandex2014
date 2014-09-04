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

void no() {
  puts("-1");
  exit(0);
}

string mirror(int n, string s) {
  for (int i = (int)s.size() - 1 - n % 2; i >= 0; i--)
    s += s[i];
  return s;
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  string s;
  int k;
  cin >> s >> k;

  if (s[0] == '-') {
    if (k < 0)
      no();
    s = "0";
    if (k == 1) {
      puts(s.c_str());
      return 0;
    }
    k--;
  }

  int n = (int)s.size();
  int n2 = (n + 1) / 2;
  string c = mirror(n, s.substr(0, n2));
  if (k > 0) {
    if (s < c) {
      k--;
      if (k == 0) {
        puts(c.c_str());
        return 0;
      }
    }

    vector<int> init(n2), a;
    forn(i, n2)
      init[i] = s[i] - '0';

    while (true) {
      a = init;

      int car = k;
      ford(i, n2) {
        a[i] += car;
        car = a[i] / 10;
        a[i] %= 10;
      }

      if (car == 0) {
        string ans;
        forn(i, n2)
          ans += '0' + a[i];
        ans = mirror(n, ans);
        puts(ans.c_str());
        return 0;
      }

      a = init;

      car = 0;
      ford(i, n2) {
        a[i] = -a[i] - car;
        car = 0;
        while (a[i] < 0) {
          a[i] += 10;
          car++;
        }
      }
      if (car > 1)
        throw;
      a.insert(a.begin(), 1 - car);

      int num = 0;
      forn(i, a.size())
        num = num * 10 + a[i];

      k -= num;

      n++;
      n2 = (n + 1) / 2;

      init = vector<int> (n2 - 1, 0);
      init.insert(init.begin(), 1);
    }
  } else {
    if (s > c) {
      k++;
      if (k == 0) {
        puts(c.c_str());
        return 0;
      }
    }

    vector<int> init(n2), a;
    forn(i, n2)
      init[i] = s[i] - '0';

    while (true) {
      a = init;

      int car = k;
      ford(i, n2) {
        a[i] += car;
        car = a[i] / 10;
        a[i] %= 10;
        while (a[i] < 0) {
          car--;
          a[i] += 10;
        }
      }

      if (car == 0 && !(a[0] == 0 && n > 1)) {
        string ans;
        forn(i, n2)
          ans += '0' + a[i];
        ans = mirror(n, ans);
        puts(ans.c_str());
        return 0;
      }

      if (n == 1)
        no();

      a = init;
      a[0]--;

      int num = 0;
      forn(i, n2)
        num = num * 10 + a[i];

      k += num + 1;

      n--;
      n2 = (n + 1) / 2;

      init = vector<int> (n2, 9);
    }
  }
  
  return 0;
}