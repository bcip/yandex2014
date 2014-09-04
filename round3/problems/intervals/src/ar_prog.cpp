#include "testlib.h"
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

int main(int argc, char* argv[]) {
  registerGen(argc, argv);
	 
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  int d = rnd.next(-1000, +1000);
  int off = rnd.next(-1000000, +1000000);
  vector<int> a(n);
  forn(i, n)
    a[i] = i * d + off;
    
  forn(i, m)
    a[rnd.next(n)] = rnd.next(-INF, +INF);

  cout << n << ' ' << d << endl;
  forn(i, n)
    printf(i ? " %d" : "%d", a[i]);
  puts("");

  return 0;
}
