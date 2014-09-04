#include "testlib.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  int n = rnd.next(-1000000000, 1000000000);
  printf("%d 1\n", n);
  return 0;
}
