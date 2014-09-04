#include "testlib.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <vector>


using namespace std;

const long long MAXN = 100000;

vector<int> g[MAXN];
set<pair<int, int> > p;
bool u[MAXN];

void dfs(int v) {
  u[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
    if (!u[g[v][i]]) {
      dfs(g[v][i]);
    }
  }
}

int main() {
  registerValidation();
  int n = inf.readInt(1, MAXN);
  inf.readEoln();

  for (int i = 0; i < n-1; ++i) {
    int x = inf.readInt(1, MAXN);
    inf.readSpace();
    int y = inf.readInt(1, MAXN);
    inf.readEoln();
    ensure(x != y);
    if (x > y) {
      swap(x, y);
    }
    ensure(p.count(make_pair(x, y)) == 0);
    p.insert(make_pair(x, y));
    g[x-1].push_back(y-1);
    g[y-1].push_back(x-1);
  }
  for (int i = 0; i < n; ++i) u[i] = false;
  dfs(0);
  for (int i = 0; i < n; ++i) ensure(u[i]);
  inf.readEof();
  return 0;
}

