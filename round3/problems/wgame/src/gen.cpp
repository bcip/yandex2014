#include "testlib.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 0);
  long long n = rnd.next(7000) + 1;
  cout << n << endl;
  return 0;
}
