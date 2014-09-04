#include "testlib.h"
#include <algorithm>
#include <iostream>


using namespace std;

const int MAXN = 300000;
const int MAX = 1000000000;

int main() {
  registerValidation();
  int n = inf.readInt(1, MAXN);
  inf.readSpace();
  int D = inf.readInt(-MAX, MAX);
  inf.readEoln();
  inf.readInt(-MAX, MAX);
  for (int i = 1; i < n; ++i) {
    inf.readSpace();
    inf.readInt(-MAX, MAX);
  }
  inf.readEoln();
  inf.readEof();
  return 0;
}

