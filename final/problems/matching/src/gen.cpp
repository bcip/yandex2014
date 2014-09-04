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
	 
	int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  int m = atoi(argv[3]);

  vector<pair<int, int> > e;
  forn(i, n1)
    forn(j, n2)
      if (rnd.next(n1 * n2 - i * n2 - j) < m - (int)e.size())
        e.pb(mp(i, j));

  shuffle(all(e));

  printf("%d %d %d\n", n1, n2, m);
  forn(i, m)
    printf("%d %d\n", e[i].fs + 1, e[i].sc + 1);
	    
  return 0;
}