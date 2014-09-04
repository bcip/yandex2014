#include "testlib.h"
#include <iostream>
#include <vector>


using namespace std;

const int MAXN = 100;

int parent[MAXN];
vector<pair<int, int> > edges;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);

  int n = rnd.next(1, MAXN);
  printf("%d\n", n);
  parent[0] = -1;
  for (int i = 1; i < n; ++i) {
    parent[i] = rnd.next(0, i-1);
  }
  for (int i = 1; i < n; ++i) {
    int x = parent[i] + 1;
    int y = i + 1;
    if (rnd.next(2) == 1) {
      swap(x, y);
    }
    edges.push_back(make_pair(x, y));
  }
  shuffle(edges.begin(), edges.end());
  for (int i = 0; i < edges.size(); ++i) {
    printf("%d %d\n", edges[i].first, edges[i].second);
  }
  return 0;
}
