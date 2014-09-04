#include "testlib.h"
#include <iostream>
#include <vector>


using namespace std;

const int MAXN = 10000000;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  int n = rnd.next(295000, 300000);
  int D = rnd.next(-MAXN, MAXN);
  int diff_numbers = rnd.next(3, 10);
  vector<int> v;
  v.push_back(rnd.next(1203, 12398));
  while (v.size() < diff_numbers) {
    v.push_back(v.back() + D);
  }
  printf("%d %d\n", n, D);
  for (int i = 0; i < n-1; ++i) {
    int id = rnd.next(v.size());
    printf("%d ", v[id]);
  }
  printf("%d\n", v[0]);
  return 0;
}
