#include "testlib.h"
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

const long long MAXN = 1000000000000000000L;
const int MAXK = 100;

int main() {
  registerValidation();
  inf.readLong(1, MAXN);
  inf.readSpace();
  inf.readInt(1, MAXK);
  inf.readEoln();
  inf.readEof();
  return 0;
}

