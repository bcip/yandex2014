#include "testlib.h"
#include <iostream>
#include <vector>


using namespace std;

const int MAXN = 1000000000;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  int n = rnd.next(295000, 300000);
  int D = rnd.next(5, 55555);
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.push_back(i);
  }
  shuffle(v.begin(), v.end());
  printf("%d %d\n", n, D);
  for (int i = 0; i < n-1; ++i) {
    printf("%d ", v[i]);
  }
  printf("%d\n", v.back());
  return 0;
}
