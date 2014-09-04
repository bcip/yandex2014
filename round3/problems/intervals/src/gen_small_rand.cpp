#include "testlib.h"
#include <iostream>


using namespace std;

const int MAXN = 1000000000;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  int n = rnd.next(5, 100);
  int D = rnd.next(-MAXN, MAXN);
  printf("%d %d\n", n, D);
  for (int i = 0; i < n-1; ++i) {
    printf("%d ", rnd.next(-MAXN, MAXN));
  }
  printf("%d\n", rnd.next(-MAXN, MAXN));
  return 0;
}
