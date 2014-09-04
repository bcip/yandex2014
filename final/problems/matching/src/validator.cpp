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

int g[1100][1100];

int main() {
  registerValidation();
  
  int n1, n2, m;
  n1 = inf.readInt(1, 10);
  inf.readSpace();
  n2 = inf.readInt(1, 100);
  inf.readSpace();
  m = inf.readInt(0, n1 * n2);
  inf.readEoln();

  for (int edge = 1; edge <= m; edge++) {
    int v1, v2;
    v1 = inf.readInt(1, n1);
    inf.readSpace();
    v2 = inf.readInt(1, n2);
    inf.readEoln();

    ensuref(g[v1][v2] == 0, "Edges %d and %d are the same.", g[v1][v2], edge);
    g[v1][v2] = edge;
  }

  inf.readEof();

  return 0;
}