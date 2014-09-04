#include "testlib.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  int n = rnd.next(-1000000000, 1000000000);
  int step = rnd.next(-1000000000, 1000000000);
  if (step == 0) ++step;
  printf("%d %d\n", n, step);
  return 0;
}
